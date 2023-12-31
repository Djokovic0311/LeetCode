class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count = 0;
        for(int num : nums) {
            if(num % 2 == 0) count++;
        }
        return count>=2;
    }
};
