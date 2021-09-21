class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = INT_MIN;
        int n = nums.size();
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            int j = i;
            while(j < n && nums[j] == 1) {
                j++;
                tmp++;
            }
            // cout << res << endl;
            res = max(res, tmp);
            tmp = 0;
        }
        return res;
    }
};