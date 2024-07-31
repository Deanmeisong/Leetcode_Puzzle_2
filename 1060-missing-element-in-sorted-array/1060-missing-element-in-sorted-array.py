class Solution(object):
    def missingElement(self, nums, k):
        l,r = 0,len(nums)-1
        while l < r:
            m = r-(r-l)//2
            if nums[m]-nums[0]-m < k: l = m
            else: r = m-1
        return nums[0]+l+k
        