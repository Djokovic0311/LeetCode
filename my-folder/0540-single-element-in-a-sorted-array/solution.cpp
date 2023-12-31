class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        while(left < right) {
            int mid = left + (right-left);
            // if the right half is even len
            bool halvesAreEven = (right - mid) % 2 == 0;
            if(nums[mid+1] == nums[mid]) {
                if(halvesAreEven) {
                    left = mid + 2;
                } else {
                    right = mid -1 ;
                }
            } else if(nums[mid-1] == nums[mid]) {
                if(halvesAreEven) {
                    right = mid - 2;
                } else {
                    left = mid + 1;
                }
            } else return nums[mid];
        }

        return nums[left];
    }
};
