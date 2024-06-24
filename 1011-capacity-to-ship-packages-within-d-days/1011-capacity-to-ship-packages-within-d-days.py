class Solution(object):
    def shipWithinDays(self, weights, days):
        left, right = 0, 0
        for w in weights:
            left = max(left, w)
            right += w
        while left < right:
            mid = (right-left)/2 + left
            cur, need = 0, 1
            for w in weights:
                if cur + w > mid:
                    need += 1
                    cur = 0
                cur += w
            if need > days: left = mid+1
            else: right = mid
        return left
            
        