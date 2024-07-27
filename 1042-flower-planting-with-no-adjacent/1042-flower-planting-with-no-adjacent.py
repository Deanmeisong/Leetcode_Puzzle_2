class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        ans = [0] * n
        g = [[] for i in range(n)]
        for (x,y) in paths:
            g[x-1].append(y-1)
            g[y-1].append(x-1)
        for i in range(n):
            ans[i] = ({1,2,3,4}-{ans[j] for j in g[i]}).pop()
        return ans