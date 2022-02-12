class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];
        for(auto n: nums)
        {
            if(n > mx) mx = n;
            if(n < mn) mn = n;
        }
        int ans = 1;
        for(int i = 2; i <= mx; i++)
        {
            if((mn % i == 0) && (mx % i == 0)) ans = i;
        }
        return ans;        
    }
};
