class Solution(object):
    def smallestRepunitDivByK(self, k):
        if k%10 not in {1, 3, 7, 9}: return -1
        mod, ms= 0, set()
        for length in range(1, k+1):
            mod = (10*mod + 1)%k
            if mod == 0: return length
            if mod in ms: return -1
            ms.add(mod)
        return -1
        