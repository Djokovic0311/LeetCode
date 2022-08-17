class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j , k = 1;
        int n = nums.size();
        for(j = 0; j < n; j++) {
            if(nums[j] == 0) k--;
            if(k < 0 && nums[i++] == 0) k++;
            cout << j << ' ' << i << endl;
        }
        return j-i-1;
    }
};
