using LL = long long;
class Solution {
public:
    LL M = 1e9+7;
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n <= 2) return (LL)cost1 * (nums[n-1] - nums[0]) % M;
        cost2 = min(2*cost1, cost2);
        LL total = accumulate(nums.begin(), nums.end(), 0LL);
        int m = nums[n-1];
        LL ret = LLONG_MAX;
        
        cost2 = min(cost1*2, cost2);
    for (int limit = m; limit <= 2*m; limit++)
        {
            LL diff0 = limit - nums[0];
            LL diff_all = (LL)limit*n - total;
            
            LL ans;
            if (diff0 <= diff_all/2)
            {
                ans = diff_all/2*cost2 + (diff_all%2==1?cost1:0);
            }
            else
            {
                ans = (diff_all - diff0)*cost2 + (diff0 - (diff_all - diff0))*cost1;
            }
            ret = min(ret, ans);
        }
        return ret%M;
    }
};