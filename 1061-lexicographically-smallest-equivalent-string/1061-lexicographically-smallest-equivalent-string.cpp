class Solution {
public:
    int fathers[26];
    // array<int, 26> fathers;
    int find(int x) {
        if(x != fathers[x]) fathers[x] = find(fathers[x]);
        return fathers[x];
    }
    void un(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;
        if(x < y) fathers[y] = x;
        else fathers[x] = y;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i = 0; i < 26; i++) fathers[i] = i;
        for(int i = 0; i < s1.size(); ++i)
            un(s1[i]-'a', s2[i]-'a');
        string res;
        for(char c : baseStr)
            res += (char)(find(c-'a') +'a');
        return res;
    }
};