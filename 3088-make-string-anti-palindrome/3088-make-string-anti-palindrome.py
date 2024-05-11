class Solution(object):
    def makeAntiPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        res = sorted(c for c in s)
        
        i = j = (n+1)//2
        while j < n and res[j] == res[i]:
            j += 1
        while res[i] == res[n-i-1]:
            if j == n: return "-1"
            res[i], res[j] = res[j], res[i]
            j += 1
            i += 1
        return "".join(res)