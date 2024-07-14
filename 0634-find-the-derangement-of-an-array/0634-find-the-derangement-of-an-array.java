class Solution {
    public int findDerangement(int n) {
        int mod = 1000000007;
        if(n == 0) return 1;
        if(n == 1) return 0;
        long[] dp = new long[n+1];
        dp[1] = 0; dp[2] = 1;
        for(int i = 3; i <= n; ++i)
            dp[i] = ((dp[i-1] + dp[i-2])*(i-1))%mod;
        return (int)dp[n];
    }
}