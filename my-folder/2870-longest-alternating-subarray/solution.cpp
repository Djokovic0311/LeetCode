class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
    int n = nums.size();
    int start = 0, end = 1;
    int maxLength = 0;

    while (end < n) {
        // move end until the sequence is no longer alternating
        while (end < n && end > start && nums[end] - nums[end-1] == ((end - start) % 2 == 0 ? -1 : 1) ) {
            // cout << end << " " << start << " " << (end - start) % 2 << endl;
            maxLength = max(maxLength, end - start + 1);
            end++;
        }

        // calculate maxLength
        // cout << end << " " << start << " " << (end - start) % 2 << endl;
        

        // update start
        start++;
        end = start+1;
    }

    return maxLength > 1 ? maxLength : -1;
    }
};
