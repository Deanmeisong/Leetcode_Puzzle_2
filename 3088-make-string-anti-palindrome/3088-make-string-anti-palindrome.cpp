class Solution {
public:
    string makeAntiPalindrome(string s) {
        int n = s.length();
        int i = (n+1)/2; int j = (n+1)/2;
        sort(s.begin(), s.end());
        while(j < n && s[i] == s[j]) ++j;
        while(s[i] == s[n-i-1]) {
            if(j == n) return "-1";
            swap(s[i++], s[j++]);
        }
        return s;
    }
};