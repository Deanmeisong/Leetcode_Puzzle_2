using LL = long long;
LL M = 1e9 + 7;
class Solution {
public:
    int numberOfWays(int n, int m, int k, vector<int>& source, vector<int>& dest) {
        LL center = 1, sr = 0, sc = 0, other = 0;
        while(k-- != 0) {
            LL pCenter = center; LL pSr = sr; LL pSc = sc; LL pOther = other;
            center = (pSr * (m - 1) + pSc * (n - 1))%M;
            sr = (pCenter + pSr * (m - 2) + pOther * (n - 1))%M;
            sc = (pCenter + pSc * (n - 2) + pOther * (m - 1))%M;
            other = (pOther * (n - 2) + pOther * (m - 2) + pSc + pSr) % M;
        }
        if(source[0] == dest[0] && source[1] == dest[1]) return center;
        else if(source[0] == dest[0]) return sr;
        else if(source[1] == dest[1]) return sc;
        return other;
    }
};