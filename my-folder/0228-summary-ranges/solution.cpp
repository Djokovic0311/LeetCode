class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
	int right;
	vector<string> ranges;
	for (int left = 0; left < nums.size(); left++) {
		right = left;
		while (right + 1 < nums.size() && nums[right] + 1 == nums[right + 1])                   right++;

		if (left == right) {
			ranges.push_back(to_string(nums[left]));
		} else {
			ranges.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
			left = right;
		}
	}
	return ranges;
    }
};
