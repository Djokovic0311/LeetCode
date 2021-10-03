class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()<=1)return nums.size();
        int answer=1,count=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                count++;
                answer=max(answer,count);
            }
            else{
                count=1;
            }
        }
        return answer;
    }
};
