class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int j = i+1, k = n-1;
            while(j < k && j < n) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < target) {
                    // cout << i << " " << j << " "  << k << endl;
                    res += (k-j);
                    j++;
                } else {
                    k--;
                }
            }
        } 
        return res;
    }
};
