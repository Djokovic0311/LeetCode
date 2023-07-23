class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long maxVal = 0;
        stack<long long> st;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            long long curr = nums[i];
            while (!st.empty() && st.top() >= curr) {
                curr += st.top();
                st.pop();
            }
            st.push(curr);
            maxVal = max(maxVal, curr);
        }
        
        return maxVal;
    }
};
