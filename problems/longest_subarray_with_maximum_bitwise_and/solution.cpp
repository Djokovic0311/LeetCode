class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int res = *max_element(nums.begin(), nums.end());
        int maxLen = 1;
        int tmp = 0;
        while(i < n) {
            if(nums[i] == res) {
                tmp = i+1;
                while(tmp < n && nums[tmp]==res)
                    tmp++;
                maxLen = max(maxLen, tmp-i);
                // cout << maxLen <<' ';
            }
            i = ++tmp;
            // cout << i << endl;
        }
        return maxLen;
    }
};