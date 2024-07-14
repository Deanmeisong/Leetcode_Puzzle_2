class Solution {
    public int findDerangement(int n) {
        int mod = 1000000007;
        if(n == 0) return 1;
        if(n == 1) return 0;
        long dp1 = 0; long dp2 = 1;
        for(int i = 3; i <= n; ++i) {
            long dp = ((dp1 + dp2)*(i-1))%mod;
            dp1 = dp2;
            dp2 = dp; 
        }
        return (int)dp2;
    }
}