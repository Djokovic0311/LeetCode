class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
		int ans = nums[0], sum = nums[0];
		for(int i = 1; i < nums.size(); i++){
			sum = nums[i] > nums[i-1] ? sum+nums[i] : nums[i]; 
			ans = max(ans, sum);
		}
		return ans;        
    }
};
