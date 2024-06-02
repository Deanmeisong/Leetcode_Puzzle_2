class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int> left(n); vector<int> right(n);
        left[0] = s[0]=='0'?0:1;
        for(int i = 1; i < n; ++i) {
            if(s[i] == '0') left[i] = left[i-1];
            else left[i] = min(left[i-1]+2, i+1);
        }
        right[n-1] = s[n-1]=='0'?0:1;
        for(int j = n-2; j >= 0; --j) {
            if(s[j] == '0') right[j] = right[j+1];
            else right[j] = min(right[j+1]+2, n-j);
        }
        
        int ret = min(left[n-1], right[0]);
        for(int i = 0; i < n-1; ++i)
            ret = min(ret, left[i]+right[i+1]);
        return ret;
    }
};