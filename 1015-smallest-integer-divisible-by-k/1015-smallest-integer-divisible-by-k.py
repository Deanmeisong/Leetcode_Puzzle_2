class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k%10 not in {1,3,7,9}: return -1
        m, ms = 0, set()
        for l in range(1, k+1):
            m = (m*10+1)%k
            if m == 0: return l
            if m in ms: return -1
            ms.add(m)
        return -1