class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> record(3,0);
        for(int num : nums)
            record[num]++;
            int idx = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < record[i]; j++) {
                nums[idx++] = i; 
            }
        }
    }
};