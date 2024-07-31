class Solution(object):
    def missingElement(self, nums, k):
        for i in range(1, len(nums)):
            gap = nums[i]-nums[i-1]-1
            if gap >= k: return nums[i-1]+k
            k -= gap
        return nums[len(nums)-1]+k
        