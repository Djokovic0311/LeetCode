class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while(left <= right){
            int mid = left + (right -left) / 2;
            int total_missing_number = nums[mid] - nums[0] - mid;
            if(total_missing_number < k){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // Skipped before l and between l i.e [l-1, l];
        // i.e. nums[l-1] - num[0] - (l-1);
        // the numbers already skipped before nums[l-1] can be subtracted
        // from k to get the remaining left.

        // add the remaining in nums[l-1] and that will be the answer;
        int skipped = nums[left-1] - nums[0] - (left-1);
        return nums[left-1] + (k-skipped);
    }
};
