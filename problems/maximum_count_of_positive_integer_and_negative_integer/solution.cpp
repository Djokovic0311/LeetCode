class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for(int num : nums) {
            if(num > 0) pos++;
            if(num < 0) neg++;
        }
        return max(neg, pos);
    }
};