class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        res = []
        for num in nums:
            s = str(num)

            for c in s:
                res.append(int(c))
        return res
        
