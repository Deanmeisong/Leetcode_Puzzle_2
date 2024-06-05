class Solution:
    def getMinDistSum(self, positions: List[List[int]]) -> float:
        def dist(a, b):
            res = 0
            for x, y in positions:
                res += math.sqrt((x-a)**2 + (y-b)**2)
            return res
        
        n = len(positions)
        curx, cury = 0, 0
        for x, y in positions:
            curx += x
            cury += y
        curx /= n
        cury /= n
        step = 1
        curDist = dist(curx, cury)
        
        while step > 0.000001:
            f = True
            for dirx, diry in [(0, step), (0, -step), (step, 0), (-step, 0)]:
                tx, ty = curx + dirx, cury + diry
                tmp = dist(tx, ty);
                if tmp < curDist:
                    f = False
                    curDist = tmp
                    curx, cury = tx, ty
            if f:
                step /= 10
        
        return curDist
