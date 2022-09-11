class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = 0;
        int res = -1;
        int mx = -1;
        while(i < n) {
            while(j < n && nums[i] == nums[j]) {
                j++;
                
            }
            // cout << j << ' ' << i << endl;
            if(nums[i] % 2 == 0 && j-i > mx)
                res = nums[i], mx = j-i;
            i = j;
        }
        return res;
    }
};