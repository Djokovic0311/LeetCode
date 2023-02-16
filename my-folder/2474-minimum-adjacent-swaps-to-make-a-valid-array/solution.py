class Solution:
    def minimumSwaps(self, nums: List[int]) -> int:
        max_val = max(nums)
        min_val = min(nums)

        min_idx = nums.index(min_val)
        max_idx = 0

        for i in range(len(nums)-1,-1,-1):
            if nums[i] == max_val:
                max_idx = i
                break
        
        if min_idx == max_idx:
            return 0

        res = 0
        if min_idx > max_idx:
            res += (min_idx-max_idx) * 2 - 1
            min_idx, max_idx = max_idx, min_idx
            
        res += len(nums) - max_idx - 1
        res += min_idx
        return res
        

