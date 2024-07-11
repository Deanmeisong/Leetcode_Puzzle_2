class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        xs = {x**i for i in range(20) if x**i < bound}
        ys = {y**j for j in range(20) if y**j < bound}
        return {x+y for x in xs for y in ys if x+y <= bound}