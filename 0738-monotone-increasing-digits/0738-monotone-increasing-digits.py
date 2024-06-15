class Solution(object):
    def monotoneIncreasingDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = list(str(n))
        change = 0
        for i in range(len(s)-1, 0, -1):
            if s[i] < s[i-1]:
                change = i
                s[i-1] = str(int(s[i-1])-1)        
        if change == 0: return n
        for i in range(change, len(s)):
            s[i] = '9'
        return int(''.join(s))
       
