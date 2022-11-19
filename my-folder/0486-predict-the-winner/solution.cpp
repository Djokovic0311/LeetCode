
class Solution {
public:
    bool scores(vector<int>& nums, bool a_turn, int score_a,int score_b, int i,int j)
    {
        if(i>j)
            return score_a>=score_b;
        
        if(a_turn)
            return scores(nums,false,score_a+nums[i],score_b,i+1,j)||scores(nums,false,score_a+nums[j],score_b,i,j-1);
            
        
        return scores(nums,true,score_a,score_b+nums[i],i+1,j)&&scores(nums,true,score_a,score_b+nums[j],i,j-1);
        
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        return scores(nums,true,0,0,0,nums.size()-1);
    }
};
