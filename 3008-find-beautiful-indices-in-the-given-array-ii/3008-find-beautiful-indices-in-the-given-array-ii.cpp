class Solution {
public:
    vector<int> kmp(string hay, string needle) {
        int n = hay.size(); int m = needle.size();
        if(n == 0 || m == 0) return {};
        vector<int> rets;
        vector<int> dp(n, 0);
        vector<int> suf = preprocess(needle);
        dp[0] = (hay[0] == needle[0]);
        if(m == 1 && dp[0] == 1) rets.push_back(0);
        for(int i = 1; i < n; ++i) {
            int j = dp[i-1];
            while(j >= 1 && hay[i] != needle[j]) j = suf[j-1];
            dp[i] = j + (hay[i] == needle[j]);
            if(dp[i] == m) rets.push_back(i - m + 1);
        }
        return rets;
    }
    vector<int> preprocess(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        for(int i=1; i < n; ++i) {
            int j = dp[i-1];
            while(j >= 1 && s[j] != s[i]) j = dp[j-1];
            dp[i] = j + (s[i] == s[j]);
        }
        return dp;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> kmp1 = kmp(s, a); vector<int> kmp2 = kmp(s, b);
        vector<int> rets;
        for(int a : kmp1) {
            auto iter1 = lower_bound(kmp2.begin(), kmp2.end(), a-k);
            auto iter2 = upper_bound(kmp2.begin(), kmp2.end(), a+k);
            if(iter2-iter1 >= 1) rets.push_back(a);
        }
        return rets;
    }
};