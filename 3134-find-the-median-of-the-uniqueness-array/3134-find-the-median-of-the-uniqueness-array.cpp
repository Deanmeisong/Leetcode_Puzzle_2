using LL = long long;
class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        LL n = nums.size();
        LL total = n*(n-1)/2 + n;
        LL half = (total + 1)/2;
        int left = 1, right = n;
        while(left < right) {
            int mid = left + (right - left)/2;
            if(check(nums, mid) >= half) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    
    LL check(vector<int>& nums, int k) {
        unordered_map<int,LL> Map;
        int i = 0;
        LL count = 0;
        for(int j = 0; j < nums.size(); ++j) {
            Map[nums[j]]++;
            while(Map.size() > k) {
                Map[nums[i]]--;
                if(Map[nums[i]] == 0) Map.erase(nums[i]);
                ++i;
            }
            count += j - i + 1;
        }
        return count;
    }
};