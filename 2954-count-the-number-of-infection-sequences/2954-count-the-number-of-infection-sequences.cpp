using LL = long long;
class Solution {
public:
    LL mod = 1e9+7;
    LL fact[100005];
    LL power[100005];
    int numberOfSequence(int n, vector<int>& sick) {
        fact[0] = 1;
        for(int i = 1; i <= n; ++i) fact[i] = (fact[i-1]*i)%mod;
        power[0] = 1;
        for(int i = 1; i <= n; ++i) power[i] = (power[i-1]*2)%mod;
        vector<int> group;
        for(int i = 0; i < sick.size(); ++i) {
            if(i == 0) group.push_back(sick[i]);
            else group.push_back(sick[i] - sick[i-1] - 1);
        }
        group.push_back(n - 1 - sick.back());
        LL total = accumulate(group.begin(), group.end(), 0LL);
        LL ret = fact[total];
        for(int x : group) ret = (ret*inv(fact[x]))%mod;
        for(int i = 1; i < sick.size(); ++i) {
            int y = sick[i] - sick[i-1] - 1;
            if(y>0) ret = (ret*power[y-1])%mod;
        }
        
        return ret;
    }
    
    LL quickMul(LL x, LL y) {
        LL ret = 1;
        LL cur = x;
        while(y) {
            if(y&1) ret = (ret*cur)%mod;
            cur = (cur*cur)%mod;
            y >>= 1;
        }
        return ret%mod;
    }
    
    LL inv(int x) {
        return quickMul(x, mod-2);
    }
};