class Solution(object):
    def maxChunksToSorted(self, arr):
        if not arr: return 0
        for i in range(1, len(arr)):
            arr[i] = max(arr[i-1], arr[i])
        count = 0
        for i in range(len(arr)):
            if arr[i] == i:
                count += 1 
        return count
        