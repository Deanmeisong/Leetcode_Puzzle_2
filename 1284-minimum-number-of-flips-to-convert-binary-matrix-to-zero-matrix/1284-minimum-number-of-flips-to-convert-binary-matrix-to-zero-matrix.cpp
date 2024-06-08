class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();
        vector<int> dirs = {0, 1, 0, -1, 0, 0};
        auto flip = [&](int s, int x, int y) {
            for(int i = 0; i < 5; ++i) {
                int nx = x + dirs[i];
                int ny = y + dirs[i+1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                s ^= (1 << (ny * n + nx));
            }
            return s;
        };
        
        int start = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                start |= (mat[i][j] << i*n + j);
        queue<int> q;
        vector<int> seen(1<<m*n);
        q.push(start);
        seen[start] = 1;
        int steps = 0;
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int s = q.front(); q.pop();
                if(s == 0) return steps;
                for(int y = 0; y < m; ++y)
                    for(int x = 0;x < n; ++x) {
                        int t = flip(s, x, y);
                        if(seen[t]) continue;
                        seen[t] = 1;
                        q.push(t);
                    }
            }
            ++steps;
        }
        return -1;
    }
};