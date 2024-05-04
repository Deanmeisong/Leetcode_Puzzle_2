using PII = pair<int,int>;
class Solution {
public:
    int diff[100005];
    int presum1[100005][26];
    int presum2[100005][26];
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        string t = s.substr(n/2, n/2); s = s.substr(0, n/2);
        reverse(t.begin(), t.end());
        int m = n/2;
        t = "#" + t; s = "#" + s;
        for(int i = 1; i <= m; ++i) diff[i] = diff[i-1] + (s[i] != t[i]);
        for(int i = 1; i <= m; ++i)
            for(int ch = 0; ch < 26; ++ch) {
                presum1[i][ch] = presum1[i-1][ch] + (s[i] == ch + 'a');
                presum2[i][ch] = presum2[i-1][ch] + (t[i] == ch + 'a');
            }
        vector<bool> rets;
        for(const auto& q : queries) {
            int a = q[0] + 1; int b = q[1] + 1;
            int c = m - 1 - (q[3] - n/2) + 1;
            int d = m - 1 - (q[2] - n/2) + 1;
            rets.push_back(process(a, b, c, d, m));
        }
        return rets;  
    }
    bool process(int a, int b, int c, int d, int m) {
        vector<PII> cross;
        if(max(a, c) <= min(b,d)) cross.push_back({max(a,c), min(b,d)});
        vector<PII> A; vector<PII> B;
        if(cross.size() == 0) {
            A.push_back({a,b});
            B.push_back({c,d});
        } else {
            if(a <= c-1) A.push_back({a, c-1});
            if(b >= d+1) A.push_back({d+1, b});
            if(c <= a-1) B.push_back({c, a-1});
            if(d >= b+1) B.push_back({b+1, d});
        }
        int count_diff = 0;
        vector<PII> Union;
        for(auto& x : cross) Union.push_back(x);
        for(auto& x : A) Union.push_back(x);
        for(auto& x : B) Union.push_back(x);
        for(auto& [s, e] : Union) count_diff += diff[e] - diff[s-1];
        if(count_diff != diff[m]) return false;      
        vector<int> count1(26); vector<int> count2(26);
        
        for(int ch = 0; ch < 26; ++ch) {
            count1[ch] = presum1[b][ch] - presum1[a-1][ch];
            count2[ch] = presum2[d][ch] - presum2[c-1][ch];
        }
        
        for(int ch = 0; ch < 26; ++ ch) {
            for(auto& [s, e] : A) count1[ch] -= presum2[e][ch] - presum2[s-1][ch];
            for(auto& [s, e] : B) count2[ch] -= presum1[e][ch] - presum1[s-1][ch];
            if(count1[ch] < 0 || count2[ch] < 0) return false;
        }
        
        for(int ch = 0; ch < 26; ++ch) {
            if(count1[ch] != count2[ch]) return false;
        }

        return true;
    }
};