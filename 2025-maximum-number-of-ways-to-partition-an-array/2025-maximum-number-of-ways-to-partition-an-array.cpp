class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        long sum = accumulate(nums.begin(), nums.end(), 0L);
        vector<long> rets(n,0);
        vector<long> pre(n);
        unordered_map<int,int> count;
        pre[0] = nums[0];
        for(int i = 1; i < n; ++i) pre[i] = pre[i-1] + nums[i];
        for(int i = 0; i < n; ++i) {
            int new_sum = sum - nums[i] + k;
            if(new_sum % 2 == 0) rets[i] += count[new_sum/2];
            count[pre[i]]++;
        }
            
        count.clear();
        vector<long> suf(n);
        suf[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; --i) suf[i] = suf[i+1] + nums[i];

        for(int i = n-1; i >= 0; --i) {
            int new_sum = sum - nums[i] + k;
            if(new_sum % 2 == 0) rets[i] += count[new_sum/2];
            count[suf[i]]++;
        }
        
        long ans = 0;
        for(int i = 0; i < n-1; ++i)
            if(sum - pre[i] == pre[i]) ++ans;
        
        for(int i = 0; i < n; ++i) ans = max(ans, rets[i]);
        return ans;
                
    }
};