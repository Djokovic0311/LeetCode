def deconstruct(aNum, aBase):
    primeComps = []  #initialise array to hold the indexes
    num = aNum
    while num >= 1:
        index = int(math.floor(math.log(num,aBase)))
        #index = ilog(num,aBase)
        num = num - (aBase ** index) 
        primeComps.append(int(aBase ** index)) # append each index into the array
    # primeComps = primeComps.sort();
    primeComps = sorted(primeComps)
    return primeComps
class Solution:

    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        res = []
        p = deconstruct(n, 2);
        # print(p)
        mod = 1e9+7
        for q in queries:
            tmp = 1
            for i in range(q[0], q[1]+1):
                tmp = (int(tmp* p[i]))%mod
            res.append(int(tmp))
        return res
            