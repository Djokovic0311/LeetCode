class Solution:
    def findMinimumTime(self, tasks: List[List[int]]) -> int:
        stack,res,active=[],0,collections.defaultdict(list)

        for i,(start,end,pt) in enumerate(tasks):    
            stack+=[(start,0,pt,i), (end,1,pt,i)]

        for t,d,pt,i in sorted(stack):        
            if 1-d:
                active[i]=[t,pt]
            else:              
                un_used=active[i][1]
                res+=un_used
                for j in active:
                    use=min(active[j][1],t-active[j][0]+1,un_used)
                    active[j][1]-=use
                    active[j][0]+=use
                del active[i]
        return res 
