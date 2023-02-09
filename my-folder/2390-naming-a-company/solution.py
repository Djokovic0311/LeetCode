def binary_search(find, list1) :
    low = 0
    high = len(list1) - 1
    while low <= high :
        mid = (low + high) // 2
        if list1[mid] == find :
            return True
        #左半边
        elif list1[mid] > find :
            high = mid -1
        #右半边
        else :
            low = mid + 1
    #未找到返回-1
    return False


class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        count = defaultdict(set)
        for a in ideas:
            count[a[0]].add(hash(a[1:]))
        res = 0
        for a, seta in count.items():
            for b, setb in count.items():
                if a >= b: continue
                same = len(seta & setb)
                res += (len(seta) - same) * (len(setb) - same)
        return res * 2
