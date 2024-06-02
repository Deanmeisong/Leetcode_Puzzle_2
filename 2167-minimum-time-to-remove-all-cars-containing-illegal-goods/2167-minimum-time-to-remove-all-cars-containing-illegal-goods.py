class Solution(object):
    def minimumTime(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        pre = [0]*n
        pre[0] = int(s[0] == '1')
        for i in range(n):
            pre[i] = pre[i-1] + int(s[i] == '1')
        arr = [0]*n
        for i in range(n):
            arr[i] = 2*pre[i] - i
        preMax = 1
        ret = n
        for i in range(n):
            ret = min(ret, arr[i] - preMax + n)
            preMax = max(arr[i], preMax)
        return ret