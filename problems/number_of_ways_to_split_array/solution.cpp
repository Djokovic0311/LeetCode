class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for(int num : nums) sum += num;
        // cout << sum << endl;
        int n = nums.size();
        int res = 0;
        long long tmp = 0;
        for(int i = 0; i < n-1; i++) {
            tmp += nums[i];
            // cout << tmp << ' ';
            if(2 * tmp >= sum) res++;
        }
        return res;
    }
};