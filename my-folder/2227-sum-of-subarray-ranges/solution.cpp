class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long int ans = 0;
        int n = nums.size(),i,j;
        long long int mx = LONG_MIN,mn = LONG_MAX;
        for(i = 0; i <n; i++){
            mx = nums[i];
            mn = nums[i];
            for(j = i; j>=0; j--){
                mx = max(mx,nums[j]*1LL);
                mn = min(mn,nums[j]*1LL);
                ans += mx-mn;
            }
        }
        return ans;
    }
};
