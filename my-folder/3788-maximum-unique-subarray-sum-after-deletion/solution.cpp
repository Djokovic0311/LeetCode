class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxVal = -101;
        int sum = 0;
        unordered_map<int, int> mp;
        for(int num : nums) {
            maxVal = max(maxVal, num);
            mp[num]++;
            if(mp[num] <= 1 && num > 0) {
                sum += num;
            }
        }
        return maxVal < 0 ? maxVal : sum;
    }
};
