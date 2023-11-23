class Solution {
    public int semiOrderedPermutation(int[] nums) {
        int n = nums.length;
        int indexOne = -1;
        int indexN = -1;
        
        for(int i=0; i<n; i++) {
            if(nums[i] == 1)
                indexOne = i;
            if(nums[i] == nums.length)
                indexN = i;
        }
        
        int count = 0;
        if(indexOne > indexN)
            count--;
        
        count += indexOne + (nums.length - 1 - indexN);
        return count;        
    }
}
