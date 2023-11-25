class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> prefix(n);
        prefix[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }

        for(int i = 0; i < n; i++) {
            int leftSum = i == 0 ? 0 : prefix[i-1];
            int leftCount = i;
            int tmp = leftCount * nums[i] - leftSum;
            int rightSum = prefix[n-1] - prefix[i];
            int rightCount = n-1-i;
            tmp += rightSum - rightCount * nums[i];
            res[i]= tmp; 
        }

        return res;
    
    }
};
