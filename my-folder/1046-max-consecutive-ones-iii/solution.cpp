class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int ans = 0;
        while(r < n && l < n) {
            cout << r << " " << l << " " << k << endl;
            if(nums[r] == 0) {
                if(k == 0) {
                    while(nums[l]!=0)
                        l++;
                    l++;
                } else {
                    k--;
                }
            }
            cout << r - l +1 << endl;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
