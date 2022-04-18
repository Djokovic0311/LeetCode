class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 0 , maxi = -1;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > maxi)
                maxi = nums[i];
            else{
                maxi++;
                cnt += maxi - nums[i];
            }
        }
        return cnt ;
    }
};