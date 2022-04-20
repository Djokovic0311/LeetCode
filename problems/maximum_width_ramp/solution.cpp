class Solution {
public:

    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        left[0] = nums[0];
        for(int i = 1; i < n; i++) {
            left[i] = min(left[i-1], nums[i]);
        }
        right[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            right[i] = max(right[i+1], nums[i]);
        }
        int l=0;
        int r=0;
        int ans=0;
        while(l<n&&r<n)
        {
            if(left[l]<=right[r])
            {
                ans=max(ans,r-l);
                r++;
            }
            else
            {
                l++;
            }
        }
        return ans;
    }

};