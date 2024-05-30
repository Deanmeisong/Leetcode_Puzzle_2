class Solution {
public:
    vector<int> z(string s){
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 1;
        for(int i=1; i < n; ++i) {
            z[i] = i > r ? 0 : min(z[i-l], r-i);
            while(z[i]+i < n && s[z[i]] == s[z[i]+i]) ++z[i];
            if(z[i]+i>r) {
                l = i;
                r = z[i] +i;
            }
        }
        return z;
    }
    long long sumScores(string s) {
        vector<int> cnt = z(s);
        return accumulate(cnt.begin(), cnt.end(), 0LL) + s.size();
    }
};