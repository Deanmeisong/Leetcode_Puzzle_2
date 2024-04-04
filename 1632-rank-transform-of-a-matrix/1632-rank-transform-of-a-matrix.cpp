class Solution {
public:
    vector<int> Father;
    int FindFather(int x) {
        if(Father[x] != x) Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    void Union(int x, int y) {
        x = Father[x]; y = Father[y];
        if(x < y) Father[y] = x;
        else Father[x] = y;
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(); int n = matrix[0].size();
        Father.resize(m*n);
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                Father[i*n+j] = i*n+j;
        vector<vector<int>> nexts(m*n);
        vector<int> inDegrees(m*n,0);
        
        for(int i = 0; i < m; ++i) {
            vector<pair<int,int>> tmp;
            for(int j = 0; j < n; ++j) tmp.push_back({matrix[i][j], i*n+j});
            sort(tmp.begin(), tmp.end());
            for(int j = 1; j < n; ++j) {
                if(tmp[j].first > tmp[j-1].first) {
                    nexts[tmp[j-1].second].push_back(tmp[j].second);
                    ++inDegrees[tmp[j].second];
                } else {
                    if(FindFather(tmp[j-1].second) != FindFather(tmp[j].second)) {
                        Union(tmp[j-1].second, tmp[j].second);
                    } 
                }
            }
        }
        
        for(int j = 0; j < n; ++j) {
            vector<pair<int,int>> tmp;
            for(int i = 0; i < m; ++i) tmp.push_back({matrix[i][j], i*n+j});
            sort(tmp.begin(), tmp.end());
            for(int i = 1; i < m; ++i) {
                if(tmp[i].first > tmp[i-1].first) {
                    nexts[tmp[i-1].second].push_back(tmp[i].second);
                    ++inDegrees[tmp[i].second];
                } else {
                    if(FindFather(tmp[i-1].second) != FindFather(tmp[i].second)) Union(tmp[i-1].second, tmp[i].second);
                }
            }
        }
    
        
        vector<vector<int>> groups(m*n);    

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                int root = FindFather(i*n+j);
                groups[root].push_back(i*n+j);
                if(root != n*i+j) inDegrees[root] += inDegrees[i*n+j];
            }
        
        queue<int> q;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(inDegrees[i*n+j] == 0 && Father[i*n+j] == i*n+j) q.push(i*n+j);
        
        int idx = 1;
        vector<vector<int>> rets(m, vector<int>(n, -1));
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                int cur = q.front(); q.pop();
                for(int a : groups[cur]) rets[a/n][a%n] = idx;
                for(int a : groups[cur]) 
                    for(int nxt : nexts[a])
                    {
                        if(--inDegrees[Father[nxt]] == 0) {
                            q.push(Father[nxt]);
                        }
                    }
            }
            ++idx;
        }
        return rets;
    }
};