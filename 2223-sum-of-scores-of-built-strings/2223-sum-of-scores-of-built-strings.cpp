class Solution {
public:
    vector<int> z(string s){
        vector<int> z(s.length());
        int l = 0, r = 1;
        for(int i = 1; i < s.length(); ++i) {
            z[i] = i > r ? 0 : min(z[i-l], r-i);
            while (i + z[i] < s.size() && s[z[i]] == s[z[i] + i]) ++z[i];
            if(z[i] + i > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    long long sumScores(string s) {
        vector<int> cnt = z(s);
        return accumulate(cnt.begin(), cnt.end(), 0LL) + s.size();
    }
};