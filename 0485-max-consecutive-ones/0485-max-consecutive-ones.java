class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ans = 0, res = 0;
        for(int x : nums)
            res = Math.max(res, ans = x == 0 ? 0 : ans + 1);
        return res;
    }
}