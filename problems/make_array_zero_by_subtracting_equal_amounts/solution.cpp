class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        unordered_set<int> st;
        for(int num : nums)
            if(num > 0)
                st.insert(num);
        
        // sort(nums.begin(),nums.end());
        // int pos = upper_bound(nums.begin(), nums.begin()+n, 0) - nums.begin();
        // cout << pos;
        return st.size();
    }
};