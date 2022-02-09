class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int> nums(n+1,0);
        nums[1] = 1;
        int mx = 0;
        for(int i = 2; i < n+1; i++) {
            if(i % 2 == 0) nums[i] = nums[i/2];
            else nums[i] = nums[i/2] + nums[i/2 + 1];
            
            mx = max(mx, nums[i]);
        }
        return mx;
    }
};