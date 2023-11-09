class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> result(k);
        stack<int> s;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {

            while (!s.empty() && nums[i] < s.top() && s.size() - 1 + n - i >= k) {
                s.pop();
            }
            // If the stack contains fewer than k elements, push the current element
            if (s.size() < k) {
                s.push(nums[i]);
            }
        }
        
        // Now pop elements from stack into result vector in reverse order to maintain sequence
        for (int i = k - 1; i >= 0; --i) {
            result[i] = s.top();
            s.pop();
        }
        
        return result;
    }
};
