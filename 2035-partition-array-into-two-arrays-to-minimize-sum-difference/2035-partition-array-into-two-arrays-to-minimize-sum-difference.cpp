using LL = long long;
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        vector<int> nums1; vector<int> nums2;
        for(int i = 0; i < n; ++i)
            nums1.push_back(nums[i]);
        for(int i = n; i < 2*n; ++i)
            nums2.push_back(nums[i]);
        LL sum = accumulate(nums.begin(), nums.end(), 0LL);
        LL ret = LLONG_MAX;
        unordered_map<int,vector<LL>> Map2 = helper(nums2);
        for(int state = 0; state < (1<<n); ++state) {
            LL x = 0;
            int i = __builtin_popcount(state);
            for(int k = 0; k < n; ++k)
                if((state>>k)&1) x += (LL)nums[k];
            int j = n - i;
            auto iter = lower_bound(Map2[j].begin(), Map2[j].end(), sum/2-x);
            if(iter != Map2[j].end()) ret = min(ret, abs(*iter*2+x*2-sum));
      
            if(iter != Map2[j].begin()) ret = min(ret, abs(*prev(iter)*2+x*2-sum));
        }
        return ret;
    }
    
    unordered_map<int, vector<LL>> helper(vector<int> nums) {
        int n = nums.size();
        unordered_map<int, vector<LL>> Map2;
        for(int state = 0; state < (1<<n); ++state) {
            int i = __builtin_popcount(state);
            LL x = 0;
            for(int k = 0; k < n; ++k)
                if((state>>k)&1) x += (LL)nums[k];
            Map2[i].push_back(x);
        }
        for(auto& x : Map2)
            sort(x.second.begin(), x.second.end());
        return Map2;
    }
};