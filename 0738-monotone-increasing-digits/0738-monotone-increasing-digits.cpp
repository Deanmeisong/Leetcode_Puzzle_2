class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int make = 0;
        for(int i = s.length()-1; i >= 1; --i) {
            if(s[i] < s[i-1]) {
                make = i;
                --s[i-1];
            }
        }
        
        if(make == 0) return n;
        
        for(int i = make; i < s.length(); ++i)
            s[i] = '9';
        
        return stoi(s);
    }
};