class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int bitsInUse = 0;
        int start = 0;
        int maxLength = 1;
        
        for(int end = 0; end < n; end++) {
            while(!((bitsInUse & nums[end]) == 0)) {
                bitsInUse ^= nums[start++];
            }
            bitsInUse |= nums[end];
            maxLength = max(maxLength, end-start+1);
        }

        return maxLength;
    }
};
