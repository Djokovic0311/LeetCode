class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i = 0; i < n; i++) {
            int s = nums[i][0], e = nums[i][1];
            for(int j = s; j <= e; j++) {
                st.insert(j);
            }
        }
        
        return st.size();
    }
};
