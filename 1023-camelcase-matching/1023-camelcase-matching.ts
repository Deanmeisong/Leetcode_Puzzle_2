class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        auto check = [](string& s, string& p) {
            int m = s.size(); int n = p.size();
            int i = 0; int j = 0;
            for(; j < n; ++i, ++j) {
                while(i < m && s[i] != p[j] && islower(s[i])) {
                    ++i;
                }
                if(i == m || s[i] != p[j]) return false;
            }
            while(i < m && islower(s[i])) {
                ++i;
            }
            return i == m;
        };
        for(string& s : queries)
            ans.push_back(check(s,pattern));
        return ans;
    }
};