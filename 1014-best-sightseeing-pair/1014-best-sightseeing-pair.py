class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        iMax, ans = values[0], 0
        for i in range(1, len(values)):
            ans = max(ans, iMax + values[i]-i)
            iMax = max(iMax, values[i]+i)
        return ans