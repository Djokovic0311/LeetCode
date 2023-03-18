class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<int> perms(n);
        perms= nums;
        int res = 0;
        int i = 0, j = 0;
        while(i < n && j < n) {
            while(i < n && j < n && nums[i] < perms[j]) {
                i++;
                j++;
                res++;
            }
            while(i < n && j < n && nums[i] >= perms[j]) {
                j++;
            }
        }
        
        return res;
        
    }
};
