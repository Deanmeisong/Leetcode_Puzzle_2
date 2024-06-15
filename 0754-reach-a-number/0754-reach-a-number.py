class Solution:
    def reachNumber(self, target: int) -> int:
        target = abs(target)
        k = int(sqrt(target * 2))
        s = k*(k+1)//2
        while s < target:
            k += 1
            s += k
        d = s - target
        if d % 2 == 0 : return k
        return k + 1 + (k+2) % 2