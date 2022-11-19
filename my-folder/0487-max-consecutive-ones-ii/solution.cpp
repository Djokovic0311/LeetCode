class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int zeros = 0;
        int mx = 0;

        for(; j < n; j++) {
            if(nums[j] == 0) {
                zeros++;
            }
            while(zeros>1) {
                if(nums[i] == 0) {
                    
                    zeros--;
                }
                i++;
            }
            mx = max(mx, j-i+1);
        }
        return mx;
    }
};
