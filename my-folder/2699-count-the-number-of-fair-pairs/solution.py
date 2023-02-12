from bisect import bisect_left, bisect_right
class Solution:
    
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums = sorted(nums)

        i = 0
        j = 0
        res = 0
        
#         while i < j and i < len(nums):
#             if nums[i] + nums[j] > upper:
#                 j-=1
#             elif nums[i] + nums[j] < lower:
#                 i+=1
#             else:
#                 res += 1
#                 i += 1
        

        def countPairSum(arr, L, R, N):

            # Sort the given array
            arr.sort()

            right = N - 1
            count = 0

            # Iterate until right > 0
            while (right > 0):

                # Starting index of element
                # whose sum with arr[right] >= L
                it1 = bisect_left(arr, L - arr[right])

                start = it1

                # Ending index of element
                # whose sum with arr[right] <= R
                it2 = bisect_right(arr, R - arr[right])

                it2 -= 1
                end = it2

                # Update the value of end
                end = min(end, right - 1)

                # Add the count of elements
                # to the variable count
                if (end - start >= 0):
                    count += (end - start + 1)

                right -= 1

            # Return the value of count
            return count
        return countPairSum(nums,lower,upper,len(nums))
