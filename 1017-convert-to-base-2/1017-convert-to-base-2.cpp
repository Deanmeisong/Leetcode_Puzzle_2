class Solution {
public:
    string baseNeg2(int n) {
        if(n == 0) return "0";
        return helper(n, -2);
    }
    
    string helper(int N, int K) {
        vector<char> ans;
        while(N) {
            int r = N%K;
            N /= K;
            if(r < 0) {
                r -= K;
                N += 1;
            }
            ans.push_back(r + '0');
        }
        return {rbegin(ans), rend(ans)};
    }
};