class Solution(object):
    def reachNumber(self, target):
        target = abs(target)
        k = s = 0
        while s < target:
            k += 1
            s += k
        d = s - target
        if d % 2 == 0 : return k
        return k + 1 + (k+2) % 2
        