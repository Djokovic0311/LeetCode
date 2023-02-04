def binary_search(alist, item):
    n = len(alist)
    start = 0
    end = n - 1
    while start <= end:
        mid = (start + end) // 2
        if alist[mid] == item:
            return True
        elif item < alist[mid]:
            end = mid - 1
        else:
            start = mid + 1
    return False

class Solution:


    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        res = 0
        tmp = 0
        banned.sort()
        # print(banned)
        for i in range(1,n+1):
            if binary_search(banned, i) == False and tmp+i <= maxSum:
                res+=1
                tmp+=i
            elif tmp+i > maxSum:
                break
            else:
                continue
                
        return res
