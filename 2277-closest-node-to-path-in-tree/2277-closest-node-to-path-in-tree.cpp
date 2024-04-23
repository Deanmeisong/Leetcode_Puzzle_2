class Solution {
public:
    vector<int> next[1005];
    int matrix[1005][1005];
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        for(auto e : edges) {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        for(int i = 0; i < n; ++i) dfs(i,i,0);
        vector<int> rets;
        
        for(auto q : query) {
            int start = q[0], end = q[1], node = q[2];
            int cur = start;
            int ret;
            int dist = INT_MAX;
            while(1) {
                if(matrix[cur][node] < dist) {
                    dist = matrix[cur][node] ;
                    ret = cur;
                }
                if(cur == end) break;
                for(int nxt : next[cur]) {
                    if(matrix[cur][end] == matrix[nxt][end] + 1) {
                        cur = nxt;
                        break;
                    }
                }
            }
            rets.push_back(ret);
        }
        
        return rets;
    }
    
    void dfs(int root, int cur, int dist) {
        for(int j : next[cur]) {
            if(j != root && matrix[root][j] == 0) {
                matrix[root][j] = dist + 1;
                dfs(root, j, dist+1);
            }
        }
    }
};