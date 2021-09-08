class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        int n = nums.size();
        if(nums[0] != 1) {
                for(int j = nums[0] - 1; j > 0; j--) {
                    res.push_back(j);
                }
            }    
        for(int i = 1; i < n; i++) {
        
            if(nums[i] - nums[i-1] > 1) {
                for(int j = nums[i-1] + 1; j < nums[i]; j++){
                    res.push_back(j);
                }
            }

            
        }
        if(nums[n-1] != n) {
                for(int j = n; j > nums[n-1]; j--) {
                    res.push_back(j);
                }
            }
        return res;
    }
};