class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1, mid;
        while(l <= h)
        {
            mid = (l + h)/2;
            if(target == nums[mid])
                return true;
            
            if(nums[l] == nums[mid] and nums[mid] == nums[h])
            {
                l++; h--;
                continue;
            }
            
            if(nums[l] <= nums[mid])             
            {
                if(nums[l] <= target and target < nums[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else                                   // right is sorted
            {
                if(nums[mid] < target and target <= nums[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return false;        
    }
};
