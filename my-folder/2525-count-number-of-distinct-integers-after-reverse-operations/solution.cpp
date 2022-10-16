class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            string tmp = to_string(nums[i]);
            reverse(tmp.begin(), tmp.end());
            nums.push_back(stoi(tmp));
        }
        set<int> st(nums.begin(), nums.end());
        // for(int s : st)
        //     cout << s << " ";
        // cout << endl;
        return st.size();
    }
};
