class Solution {
public:
    int smaller[100005];
    int count[100005];
    int sorted[100005];
    int m = 1e9 + 7;
    int createSortedArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) sorted[i] = nums[i];
        helper(nums, 0, n-1);
        int ret = 0;
        for(int i = 0; i < n; ++i) {
            ret += min(smaller[i], i - smaller[i] - count[nums[i]]);
            ret %= m;
            count[nums[i]]++;
        }
        return ret;
    }
    void helper(vector<int>& nums, int a, int b) {
        if(a >= b) return;
        int mid = (b-a)/2 + a;
        helper(nums, a, mid);
        helper(nums, mid+1, b);
        for(int i = mid+1; i <= b; ++i) {
            auto iter = lower_bound(sorted+a, sorted+mid+1, nums[i]);
            smaller[i] += iter - (sorted+a);
        }
        inplace_merge(sorted+a, sorted+mid+1, sorted+b+1);
    }
};