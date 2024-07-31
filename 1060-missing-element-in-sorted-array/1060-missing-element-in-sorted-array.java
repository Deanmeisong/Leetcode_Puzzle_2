class Solution {
    public int missingElement(int[] nums, int k) {
        int l = 0, r = nums.length-1;
        while(l<r) {
            int m = r-(r-l)/2;
            if(nums[m]-nums[0]-m < k) l = m;
            else r = m-1;
        }
        return nums[0]+l+k;
    }
}