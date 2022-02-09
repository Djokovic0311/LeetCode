class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[j]== nums[i]) res++;
            }
        }
        return res;
    }
};