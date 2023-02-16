# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, row: int, col: int) -> int:
#    def dimensions(self) -> list[]:

class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        row, col = binaryMatrix.dimensions()
        res = sys.maxsize

        def valid(j: int):
            i = 0
            while i < row:
                if binaryMatrix.get(i, j):
                    return True
                i += 1
            return False
        

        if not valid(col-1):                      # If the last column is not valid all columns are 0
            return -1
        
        lo, hi = 0, col - 1                       # Binary search
        while lo <= hi:
            mid = hi + (lo - hi)//2
            if valid(mid):
                hi = mid - 1
            else:
                lo = mid + 1
                
        return lo  
