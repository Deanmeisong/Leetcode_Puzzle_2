public class Solution {
    public int FindMaxConsecutiveOnes(int[] nums) {
       int ans = 0, res = 0;
        foreach (int x in nums) {
            ans = (x == 0) ? 0 : ans + 1;
            res = Math.Max(res, ans);
        }
        return res;
        
    }
}