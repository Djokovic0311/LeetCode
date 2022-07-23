class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int i = 0, j = 0;
        while(i < n && j < n) {
            while(i < n && nums[i] != 0) i++;
            j = i;
            while(j < n && nums[j] == 0) j++;
            res += ((long long)(j-i+1)) * ((long long)(j-i))/2;
            i = j;
        }
        return res;
    }
};