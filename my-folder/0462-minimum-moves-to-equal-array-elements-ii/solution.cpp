class Solution {
public:
    int minMoves2(vector<int>& nums) {

	sort(begin(nums), end(nums));
	int moves = 0, median = nums[size(nums) / 2];
	for(auto num : nums) moves += abs(num - median);
	return moves;        
    }
};
