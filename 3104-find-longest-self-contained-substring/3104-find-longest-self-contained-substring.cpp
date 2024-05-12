class Solution {
public:
    int maxSubstringLength(string s) {
        int n = s.length();
        map<int, int> first; map<int, int> last;
        for(int i = 0; i < n; ++i) {
            if(first.find(s[i]-'a') == first.end()) first[s[i]-'a'] = i;
            last[s[i] - 'a'] = i;
        }
        int ans = -1;
        for(auto& [c, i] : first) {
            int mx = last[c];
            for(int j = i; j < n; ++j) {
                int a = first[s[j]-'a']; int b = last[s[j]-'a'];
                if(a < i) break;
                mx = max(mx, b);
                if(mx == j && j - i + 1 < n) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};