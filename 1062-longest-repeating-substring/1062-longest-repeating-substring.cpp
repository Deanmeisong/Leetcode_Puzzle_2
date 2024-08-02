class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int ans = 0, n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j < i; ++j) {
                if(s[i-1] == s[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        return ans;
    }
};