class Solution:
    def pourWater(self, heights: List[int], volume: int, k: int) -> List[int]:
        while volume != 0:
            l = r = k
            for i in range(k-1,-1,-1):
                if heights[i] > heights[l]:
                    break
                elif heights[i] < heights[l]:
                    l = i

            if l < k:
                heights[l] += 1
            else:
                for j in range(k+1, len(heights)):
                    if heights[j] > heights[r]:
                        break
                    elif heights[j] < heights[r]:
                        r = j
            
            if r > k:
                heights[r] += 1
            elif l == r == k:
                heights[k] += 1

            volume -= 1

        return heights
