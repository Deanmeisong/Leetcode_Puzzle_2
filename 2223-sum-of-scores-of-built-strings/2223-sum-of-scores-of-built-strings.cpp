class Solution {
public:
    vector<int> kmp(string s) {
        int n = s.length();
        vector<int> dp(n);
        dp[0] = 0;
        for(int i = 1; i < n; ++i) {
            int j = dp[i-1];
            while(j && s[j] != s[i]) j = dp[j-1];
            dp[i] = j + (s[i] == s[j]);
        }
        return dp;
    }
    long long sumScores(string s) {
        vector<int> cnt;
        for(int x :kmp(s)) {
            cnt.push_back(x == 0 ? 0 : cnt[x-1] + 1);
        }
        return accumulate(cnt.begin(), cnt.end(), 0LL) + s.length();
    }
};