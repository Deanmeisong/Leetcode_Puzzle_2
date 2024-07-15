class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        const int ml = 10;
        int n = s.length();
        unordered_set<string> dict(words.begin(), words.end());
        vector<int> b(n, 0);
        for(int i = 0; i < n; ++i)
            for(int l = 1; l <= min(ml, n-i); ++l)
                if(dict.count(s.substr(i, l)))
                    std::fill(b.begin()+i, b.begin()+i+l, 1);

                
        string ans;
        for(int i = 0; i < n; ++i) {
            if(b[i] && (i == 0 || !b[i-1])) ans += "<b>";
            ans += s[i];
            if(b[i] && (i == n - 1 || b[i+1] == 0)) ans += "</b>";
        }
        return ans;
        
        
    }
};