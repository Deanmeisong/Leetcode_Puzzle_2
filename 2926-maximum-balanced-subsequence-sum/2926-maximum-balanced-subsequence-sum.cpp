using LL = long long;
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) arr[i] = nums[i] - i;
        map<int, LL> dp;
        LL ret = LLONG_MIN;
        
        for(int i = 0; i < n; ++i) {
            int x = arr[i];
            LL y = (LL)nums[i];
            auto iter = dp.upper_bound(x);
            if(iter != dp.begin()) {
                iter = prev(iter);
                dp[x] = max(iter->second + y, y);
            } else {
                dp[x] = y;
            }
            
            ret = max(ret, dp[x]);
            iter = dp.find(x);
            iter = next(iter);
            while(iter != dp.end() && iter->second <= dp[x]) iter = dp.erase(iter);
           
        }
        
        return ret;
    }
};