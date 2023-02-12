class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        res = 0
        graph = collections.defaultdict(list)
        for i,j in roads:
            graph[i].append(j)
            graph[j].append(i)

        def dfs(node, par):
            nonlocal res
            totalPeople = 1

            for nei in graph[node]:
                if nei != par:
                    people, car = dfs(nei, node)
                    totalPeople += people
                    res += car
                    
            cars = math.ceil(totalPeople/seats)
            return totalPeople, cars
        dfs(0,None)
        return res



