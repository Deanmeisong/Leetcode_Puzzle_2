using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    LL dp[10001][15];
    int idealArrays(int n, int maxValue) {
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
            for(int j = 1; j <= 14; ++j)
                for(int k = 0; k <= j; ++k)
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k])%M;
        }
        vector<int> primes = getPrimes(maxValue);

        
        LL ret = 0;
        for(int t = 1; t <= maxValue; ++t) {
            int x = t;
            LL ans = 1;
            for(int p : primes) {
                int count = 0;
                while(x > 1 && (x % p == 0)) {
                    ++count;
                    x /= p;
                }
                ans = (ans * dp[n][count])%M;
            }
            ret = (ret + ans)%M;

        }
        return ret;
    }
    
    vector<int> getPrimes(int n) {
        vector<int> q(n+1, 0);
        vector<int> primes;
        for(int i = 2; i <= sqrt(n); ++i) {
            if(q[i] == 1) continue;
            int j = 2*i;
            while(j <= n) {
                q[j] = 1;
                j += i;
            }
        }
        for(int i = 2; i <= n; ++i)
            if(q[i] == 0) primes.push_back(i);
        return primes;
    }
};