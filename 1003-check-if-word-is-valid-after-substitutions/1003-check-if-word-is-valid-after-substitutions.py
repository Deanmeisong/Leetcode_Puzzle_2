class Solution(object):
    def isValid(self, s):
        chars = []
        for c in s:
            chars.append(c)
            n = len(chars)
            if n >= 3 and chars[n-3] == 'a' and chars[n-2] == 'b' and chars[n-1] == 'c':
                chars.pop()
                chars.pop()
                chars.pop()
        return len(chars) == 0