class DetectSquares:

    def __init__(self):
        self.points=defaultdict(lambda :defaultdict(int))
    def add(self, point: List[int]) -> None:
        x,y = point
        self.points[y][x]+=1
    def count(self, point: List[int]) -> int:
        X,Y = point
        count = 0
        for x in self.points[Y]:
            d=abs(x-X)
            if d==0:continue
            count+=(self.points[Y-d][x]*self.points[Y-d][X]*self.points[Y][x])
            count+=(self.points[Y+d][x]*self.points[Y+d][X]*self.points[Y][x])
        return count

# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)
