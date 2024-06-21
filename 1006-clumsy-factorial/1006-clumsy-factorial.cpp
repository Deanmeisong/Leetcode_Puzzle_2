class Solution {
public:
    int clumsy(int n) {
        long long ans = 0;
        bool p = true;
        while(n) {
            if(n >= 4) {
                ans += (p ? (long long)n : -(long long)n) * (n-1) / (n-2) + (n-3);
                p = false;
                n -= 4;
            } else if(n == 3) {
                ans += (p ? (long long)n : -(long long)n) * (n-1) / (n-2);
                break;
            } else if(n == 2) {
                ans += (p ? (long long)n : -(long long)n) * (n-1);
                break;
            } else {
                ans += (p ? (long long)n : -(long long)n);
                break;
            }
        }
        return ans;
    }
};
