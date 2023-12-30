class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            sum.push_back(nums[i] + sum[i-1]);
        }
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? sum[right] : sum[right] - sum[left-1];
    }
private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
