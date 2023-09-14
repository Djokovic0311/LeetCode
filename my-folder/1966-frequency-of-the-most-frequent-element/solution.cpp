class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int r = 0;
        int ans = 0;
        for(int l = 0; l < nums.size(); l++)
        {
            while(r < nums.size() && nums[l]-nums[r] <= k)
            {
                k -= (nums[l]-nums[r]);
                r++;
            }

            if(l < nums.size()-1) 
                k += (nums[l]-nums[l+1]) * (r-l-1);
            ans = max(ans, r-l);
        }
        return ans;
    }
};
