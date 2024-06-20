class RLEIterator:

    def __init__(self, encoding: List[int]):
        self.i = 0
        self.j = 0
        self.encoding = encoding

    def next(self, n: int) -> int:
        while self.i < len(self.encoding):
            if n > self.encoding[self.i] - self.j:
                n -= self.encoding[self.i] - self.j
                self.j = 0
                self.i += 2
            else:
                self.j += n
                return self.encoding[self.i+1]
        return -1
        


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(encoding)
# param_1 = obj.next(n)