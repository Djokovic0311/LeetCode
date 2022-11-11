class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int n = nums.size();
        if(n==0)
            return n;
        int fast = 1, slow =1;
        while(fast < n){
            if(nums[fast] != nums[fast-1]){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;       
    }
};
