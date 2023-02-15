class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        l = [i for i in range(1,n+1)]
        k = k-1
        index = 0
        def helper(k, index):
            if len(l) == 1:
                return l[0]
            index = (index + k) % len(l)
            
            del l[index]
            return helper(k,index)
        return helper(k,0)

