using LL = long long;
class Solution {
public:
    LL dp0[1005][1005]; LL dp1[1005][1005]; LL presum1[1005][1005]; LL presum0[1005][1005];
    LL M = 1e9 + 7;
    int numberOfStableArrays(int zero, int one, int limit) {
        dp0[0][0] = 1; dp1[0][0] = 1; presum1[0][0] = 1; presum0[0][0] = 1;
        for(int i = 0; i <= zero; ++i)
            for(int j = 0; j <= one; ++j) {
                if(i == 0 && j == 0) continue;
                dp0[i][j] = i-1 < 0 ? 0 : presum1[j][i - 1] - (i-limit-1 < 0 ? 0 : presum1[j][i - limit - 1]);
                dp1[i][j] = j-1 < 0 ? 0 : presum0[i][j - 1] - (j-limit-1 < 0 ? 0 : presum0[i][j - limit - 1]);
                
                dp0[i][j] = (dp0[i][j] + M) % M;
                dp1[i][j] = (dp1[i][j] + M) % M;
                
                presum0[i][j] = (j<1?0:presum0[i][j-1]) + dp0[i][j];
                presum1[j][i] = (i<1?0:presum1[j][i-1]) + dp1[i][j];

                
                presum1[j][i] = ((i-1 < 0 ? 0 : presum1[j][i-1]) + dp1[i][j]) % M;
                presum0[i][j] = ((j-1 < 0 ? 0 : presum0[i][j-1]) + dp0[i][j]) % M;
            }
        return (dp0[zero][one] + dp1[zero][one]) % M;
    }
};