class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int iMax = values[0]; int ans = 0;
        for(int i = 1; i < values.length; ++i) {
            ans = Math.max(ans, iMax + values[i] - i);
            iMax = Math.max(iMax, values[i] + i);
        }
        return ans;
    }
}