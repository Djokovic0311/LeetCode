class Solution {
    public int reductionOperations(int[] nums) {
        int n = nums.length;
        int res = 0;
        Arrays.sort(nums);
        for(int i = n-1; i> 0; i--) {
            if(nums[i] != nums[i-1]) {
                res += n - i;
            }
        }

        return res;
    }
}
