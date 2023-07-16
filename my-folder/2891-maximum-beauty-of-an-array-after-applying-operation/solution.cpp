class Solution {
public:

    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> max_val(n), min_val(n);

        // Calculate the maximum and minimum possible values for every number
        for(int i = 0; i < n; i++) {
            max_val[i] = min(nums[i] + k, 100000);
            min_val[i] = max(nums[i] - k, 0);
        }

        // Sort the possible values
        sort(max_val.begin(), max_val.end());
        sort(min_val.begin(), min_val.end());

        // Use a sliding window to find the maximum overlap
        int max_beauty = 0;
        int j = 0;
        for(int i = 0; i < n; i++) {
            while(j < n && max_val[j] < min_val[i]) {
                j++;
            }
            max_beauty = max(max_beauty, i - j + 1);
        }
        return max_beauty;   
    }
};
