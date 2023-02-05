import queue
import math
class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        pq=queue.PriorityQueue()
        for gift in gifts:
            pq.put(-gift)
        
        while k:
            k-=1
            tmp = pq.get()
            # print(-tmp)
            # print(math.floor(math.sqrt(-tmp)))
            pq.put(-math.floor(math.sqrt(-tmp)))
            
        res = 0
        while not pq.empty():
            res += pq.get()
            print(res)
            # pq.pop()
        
        return -res
            
        
