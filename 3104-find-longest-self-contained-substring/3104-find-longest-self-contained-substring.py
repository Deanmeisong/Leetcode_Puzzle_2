class Solution(object):
    def maxSubstringLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans, n = -1, len(s)
        first, last = {}, {}
        for i, c in enumerate(s):
            if c not in first: first[c] = i
            last[c] = i
        
        for c, i in first.items():
            mx = last[c]
            for j in range(i, n):
                a, b = first[s[j]], last[s[j]]
                if a < i: break
                mx = max(mx, b)
                if mx == j and j - i + 1 < n:
                    ans = max(ans, j - i + 1)
        return ans