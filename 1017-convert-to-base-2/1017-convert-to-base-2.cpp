class Solution {
public:
    string baseNeg2(int n) {
        if(n == 0) return "0";
        string s;
        while(n) {
            s = to_string(n&1) + s;
            n = -(n>>1);
        }
        return s;
    }
};