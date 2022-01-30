class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        long long tmp = nums[0];
        vector<bool> res;
        res.push_back(tmp % 5 == 0);
        for(int i = 1; i < n; i++) {
            tmp = (tmp * 2 + nums[i]) % 5;
            // cout << tmp <<endl;
            res.push_back(tmp==0);
        }
        return res;
    }
};