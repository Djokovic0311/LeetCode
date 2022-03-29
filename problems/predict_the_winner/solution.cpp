class Solution {
public:
    int helper(vector<int>& nums, int i, int j, int chance) {
        if(i > j) return 0;
        if(chance == 0) {
            return max(nums[i] + helper(nums, i+1, j, 1), nums[j] + helper(nums, i, j-1,1));
        }
        else return min(helper(nums,i + 1,j,0) ,helper(nums,i,j-1,0));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int player2 = 0;
                
        for(auto x:nums) player2+=x;
        
        
         int player1=helper(nums,0,nums.size() - 1,0);
        player2-=player1;
        
        return player1>=player2;
    }
};