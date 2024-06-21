class Solution {
public:
    bool isValid(string s) {
        vector<char> chars;
        for(char c : s) {
            chars.push_back(c);
            int n = chars.size();
            if(n >= 3) {
                if(chars[n-3] == 'a' && chars[n-2] == 'b' && chars[n-1] == 'c') {
                    chars.pop_back(); chars.pop_back(); chars.pop_back();
                }
            }
        }
        return chars.size() == 0;
    }
};