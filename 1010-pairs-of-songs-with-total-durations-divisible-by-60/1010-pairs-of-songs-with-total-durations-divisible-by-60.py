class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        res = 0
        c = [0] * 60
        for t in time:
            res += c[-t%60]
            c[t%60] += 1
        return res