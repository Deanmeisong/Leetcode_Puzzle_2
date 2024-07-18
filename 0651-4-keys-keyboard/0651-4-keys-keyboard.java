class Solution {
    public int maxA(int n) {
        int[] dp = new int[n+1];
        for(int i = 1; i <= n; ++i) {
            dp[i] = i;
            for(int j = 1; j < i-2; ++j) {
                int total = dp[j] + dp[j]*(i-j-2);
                dp[i] = Math.max(dp[i], total);
            }
        }
        return dp[n];
    }
}