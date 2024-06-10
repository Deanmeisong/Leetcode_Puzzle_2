class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans, tmp = 0, 0
        for x in nums:
            tmp = 0 if x == 0 else tmp + 1
            ans = max(ans, tmp)
        return ans