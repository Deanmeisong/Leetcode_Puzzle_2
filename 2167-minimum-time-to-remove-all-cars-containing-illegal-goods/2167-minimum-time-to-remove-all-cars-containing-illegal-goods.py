class Solution:
    def minimumTime(self, s: str) -> int:
        n = len(s)
        pre = [0] * n
        pre[0] = int(s[0] == '1')
        for i in range(n):
            pre[i] = pre[i-1] + int(s[i] == '1')
        arr = [0] * n
        for i in range(n):
            arr[i] = 2*pre[i] - i
        
        ret, preMax = n, 1
        for i in range(n):
            ret = min(ret, arr[i] - preMax + n)
            preMax = max(preMax, arr[i])
        return ret
