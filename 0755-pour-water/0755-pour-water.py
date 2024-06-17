class Solution:
    def pourWater(self, heights: List[int], volume: int, k: int) -> List[int]:
        def drop(h, k):
            best = k
            for d in [-1,1]:
                i = k+d
                while i >= 0 and i < len(h) and h[i] <= h[i-d]:
                    if h[i] < h[best]: best = i
                    i += d
                if best != k: break
            h[best] += 1
        
        for _ in range(volume):
            drop(heights, k)
        return heights