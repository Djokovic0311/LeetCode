class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> vec(st.begin(), st.end());
        sort(vec.begin(), vec.end(), greater<int>());
        if(vec.size() > k) {
            vec.resize(k);
        }
        
        return vec;
    }
};
