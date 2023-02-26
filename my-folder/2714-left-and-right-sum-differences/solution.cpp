class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,0), right(n,0);
        for(int i = 0; i < n-1; i++) {
            left[i+1] = left[i] + nums[i];
        }
        for(int i = n-1; i > 0; i--) {
            right[i-1] = right[i] + nums[i];
        }
        
        vector<int> res;
        for(int i = 0; i < n; i++) {
            res.push_back(abs(left[i]-right[i]));
        }
        
        return res;
            
    }
};
