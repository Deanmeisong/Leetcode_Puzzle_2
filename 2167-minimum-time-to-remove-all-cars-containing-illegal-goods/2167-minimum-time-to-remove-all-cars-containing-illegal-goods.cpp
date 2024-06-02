class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        vector<int> presum(n);
        presum[0] = (s[0] == '1');
        for(int i = 1; i < n; ++i)
            presum[i] = presum[i-1] + (s[i] == '1');
        vector<int> arr(n);
        for(int i = 0; i < n; ++i)
            arr[i] = 2*presum[i] - i;
        int preMax = 1;
        int ret = n;
        for(int i = 0; i < n; ++i) {
            ret = min(arr[i] - preMax + n, ret);
            preMax = max(preMax, arr[i]);
        }
        return ret;
    }
};