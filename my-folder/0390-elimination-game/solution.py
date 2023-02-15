class Solution:
    def lastRemaining(self, n: int) -> int:
        if n%2: n = n-1
        if not n: return 1 
        return n - 2*(self.lastRemaining(n//2)-1)


