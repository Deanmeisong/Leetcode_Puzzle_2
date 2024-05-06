class Solution {
public:
    vector<int> pp(string s) {
        int n = s.length();
        vector<int> dp(n,0);
        for(int i = 1; i < n; ++i) {
            int j = dp[i-1];
            while(j >= 1 && s[i] != s[j]) j = dp[j-1];
            dp[i] = j + (s[j] == s[i]);
        }
        return dp;
    }
    vector<int> kmp(string hay, string needle) {
        int n = hay.length(); int m = needle.length();
        if(n == 0 || m == 0) return {};
        vector<int> suff = pp(needle);
        vector<int> dp(n, 0);
        dp[0] = (hay[0] == needle[0]);
        vector<int> rets;
        if(dp[0] == 1 && m == 1) rets.push_back(0);
        for(int i = 1; i < n; ++i) {
            int j = dp[i-1];
            while(j >= 1 && hay[i] != needle[j]) j = suff[j-1];
            dp[i] = j + (hay[i] == needle[j]);
            if(dp[i] == m) rets.push_back(i-m+1);
        }
        return rets;

    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> A = kmp(s, a);
        vector<int> B = kmp(s, b);
        vector<int> rets;
        for(int a : A) {
            auto it1 = lower_bound(B.begin(), B.end(), a-k);
            auto it2 = upper_bound(B.begin(), B.end(), a+k);
            if(it2-it1 >= 1) rets.push_back(a);
        }
        return rets;

    }
};