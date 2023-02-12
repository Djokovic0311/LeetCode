class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        res = 0
        for i in range(len(nums)//2):
            res += int(str(nums[i]) + str(nums[len(nums)-1-i]))
        if len(nums) % 2 != 0:
            res += nums[len(nums)//2]
        return res
