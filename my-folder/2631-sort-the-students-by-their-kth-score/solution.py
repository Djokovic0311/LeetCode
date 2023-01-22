class Solution:
    def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
        score = sorted(score,key = lambda x:x[k])
        score.reverse()
        return score


        
