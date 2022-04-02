class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> com = nums;
        sort(com.begin(),com.end());
        int n = nums.size();
        int res = n;
        int i = 0, j = n-1;
        while(i < n) {
            if(nums[i] == com[i]) res--, i++;
            else break;
        }
        while(j >= 0) {
            if(nums[j] == com[j]) res--,j--;
            else break;
        }
        return max(res,0);
    }
};