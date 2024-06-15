class Solution(object):
    def openLock(self, deadends, target):
        deadSet = set(deadends)
        if "0000" in deadSet: return -1
        steps = 0
        q = deque(["0000"])
        while q:
            for _ in range(len(q)):
                curr = q.popleft()
                if curr == target: return steps
                for nei in self.neigs(curr):
                    if nei in deadSet: continue
                    deadSet.add(nei)
                    q.append(nei)
            steps += 1
        return -1
    def neigs(self, code):
        for i in range(4):
            x = int(code[i])
            for diff in [-1,1]:
                y = (x+diff+10)%10
                yield code[:i] + str(y) + code[i+1:]
    