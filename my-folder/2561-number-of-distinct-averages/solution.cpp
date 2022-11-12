class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<double> st;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n/2; i++) {
            st.insert((double(nums[i]) + double(nums[n-1-i]))/2.0);
        }
        return st.size();
    }
};
