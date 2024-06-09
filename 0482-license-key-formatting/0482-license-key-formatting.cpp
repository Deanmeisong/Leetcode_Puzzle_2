class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] != '-') {
                if (ans.size()%(k+1) == k) ans += '-';
                ans += toupper(s[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};