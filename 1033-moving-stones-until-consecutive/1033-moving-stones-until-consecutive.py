class Solution(object):
    def numMovesStones(self, a, b, c):
        x, z = min(a, b, c), max(a, b, c)
        y = a+b+c-x-z
        mi = ma = 0
        if z-x > 2:
            mi = 1 if y-x < 3 or z-y < 3 else 2
            ma = z-x-2
        return [mi, ma]
        