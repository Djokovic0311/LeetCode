class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            minPrice = min(minPrice, nums[i]);
            maxPro = max(maxPro, nums[i] - minPrice);
        }
            if(maxPro==0) return -1;
            return maxPro;
    
    }
};