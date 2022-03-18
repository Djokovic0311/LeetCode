class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for ( int i = 0; i < nums.size(); i++) {
            bool found = false;
            for ( int j = 0; j < nums.size(); j++) {
                if ( nums[i] == nums[j] && i != j) {
                    found = true;
                }
            }
            if ( !found ) {
                return nums[i];
            }
        }
        return -1;
    }
};