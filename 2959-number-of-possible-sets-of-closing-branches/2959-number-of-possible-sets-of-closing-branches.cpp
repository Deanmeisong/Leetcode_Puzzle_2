class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ret = 0;
        for(int state = 0; state < (1<<n); ++state) {
            vector<vector<int>> dp(n, vector<int>(n, INT_MAX/3));
            for(int i = 0; i < n; ++i) 
                if((state>>i)&1) dp[i][i] = 0;
            for(const auto& road : roads) {
                int a = road[0], b = road[1], w = road[2];
                if((state>>a)&1^1) continue;
                if((state>>b)&1^1) continue;
                for(int i = 0; i < n; ++i) {
                    if((state>>i)&1^1) continue;
                    for(int j = 0; j < n; ++j) {
                        if((state>>j)&1^1) continue;
                        dp[i][j] = min(dp[i][j], dp[i][a] + w + dp[b][j]);
                        dp[i][j] = min(dp[i][j], dp[i][b] + w + dp[a][j]);
                    }
                }    
            }
            int flag = 0;
            for(int i = 0; i < n; ++i) {
                if(((state>>i)&1)^1) continue;
                for(int j = 0; j < n; ++j) {
                    if(((state>>j)&1)^1) continue;
                    if(dp[i][j] > maxDistance) {
                        flag = 1;
                        break;
                    }
                    if(flag) break;
                }
            }
            ret += (flag^1);
            
        }
        return ret;
    }
};