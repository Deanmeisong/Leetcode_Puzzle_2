class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int mid = r-(r-l)/2;
            if(nums[mid]-nums[0]-mid < k) l = mid;
            else r = mid-1;
        }
        return nums[0]+l+k;
    }
};