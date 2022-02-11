class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int tmp = nums[0];
        int res = 0;
        if(n == 1) return 0;
        for(int i = 1; i<n; i++) {
            if(nums[i] > nums[i-1]) tmp = nums[i];
            else tmp = nums[i-1] + 1;
            cout << tmp << endl;
            res += (tmp - nums[i]);
            nums[i] = tmp;
        }
        return res;
    }
};