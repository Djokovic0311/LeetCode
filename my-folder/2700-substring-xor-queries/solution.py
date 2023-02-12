
class Solution:
    def substringXorQueries(self, s: str, queries: List[List[int]]) -> List[List[int]]:
        res = []
        def dec2bin(num):
            return bin(num).replace('0b', '')
	
            # l = []
            # while True:
            #     num, remainder = divmod(num, 2)
            #     l.append(str(remainder))
            #     if num == 0:
            #         return ''.join(l[::-1])
        match = defaultdict()
        
        for q in queries:
            sub = q[0] ^ q[1]
            s_ = dec2bin(sub)
            if s_ not in s:
                res.append([-1, -1])
            else:
                if s_ in match:
                    res.append([match[s_], match[s_]+len(s_)-1])
                else:
                    pos = s.find(s_)
                    match[s_] = pos 
                    res.append([pos,pos+len(s_)-1])
                
        return res
    

