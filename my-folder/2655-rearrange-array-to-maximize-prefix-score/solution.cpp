class Solution {
public:
    int maxScore(vector<int>& nums) {
        // Count the frequency of each integer in nums

        // Calculate the maximum score by counting positive prefix sums
        int maxScore = 0;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum > 0) maxScore++;
            else break;
        }
        
        return maxScore;        
    }
};
