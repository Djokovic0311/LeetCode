class Solution {
public:
    int jump(vector<int>& nums) {
	int n = size(nums), i = 0, maxReachable = 0, lastJumpedPos = 0, jumps = 0;
	while(lastJumpedPos < n - 1) {  
		maxReachable = max(maxReachable, i + nums[i]);  
		if(i == lastJumpedPos) {			  
			lastJumpedPos = maxReachable;     // so just move to that maxReachable position
			jumps++;                          // and increment the level
		}            
		i++;
	}
	return jumps;
    }
};