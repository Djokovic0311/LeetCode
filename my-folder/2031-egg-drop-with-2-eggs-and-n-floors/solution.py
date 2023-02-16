class Solution:
    def twoEggDrop(self, n: int) -> int:
            # 1. set up an interval as 1
        interval = 1
        
        # 2. count down from n until it's <= 0, reducing by the interval, and increasing the interval each time
        while n > 0:
            n -= interval
            interval += 1
        
        # 3. return interval - 1
        return interval - 1
