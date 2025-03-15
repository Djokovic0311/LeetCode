class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int mincap = 1, maxcap = *max_element(nums.begin(), nums.end());

        while(mincap < maxcap) {
            int mid = mincap + (maxcap - mincap) / 2;
            int theftCount = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] <= mid) {
                    theftCount++;
                    i++;
                }
            }

            if(theftCount >= k) {
                maxcap = mid;
            } else {
                mincap = mid+1;
            }
        }

        return mincap;
    }
};
