class Solution:
    def getMinDistSum(self, positions: List[List[int]]) -> float:
        def dist(a, b):
            res = 0
            for x, y in positions:
                res += math.sqrt((x-a)**2 + (y-b)**2)
            return res
        n = len(positions)
        step = 1
        curx = cury = 0
        for x, y in positions:
            curx += x
            cury += y
        curx /= n
        cury /= n
        
        curdist = dist(curx, cury)

        while step > 0.000001:
            f = True
            for dirx, diry in [(step, 0), (-step, 0), (0, step), (0, -step)]:
                tx, ty = curx + dirx, cury + diry
                tmp = dist(tx, ty)
                if tmp < curdist:
                    curdist, curx, cury, f = tmp, tx, ty, False
            if f:
                step /= 10
        
        return curdist
                