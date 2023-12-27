class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        stack<int> stk;
        stk.push(-1);
        for(int i = 0; i < n; i++) {
            while(stk.top() != -1 && heights[stk.top()] >= heights[i]) {
                int h = heights[stk.top()];
                stk.pop();
                int w = i - stk.top() - 1;
                res= max(res, h * w);
            }
            stk.push(i);
        }
        while(stk.top() != -1) {
            int h = heights[stk.top()];
            stk.pop();
            int w = n - stk.top() - 1;
            res = max(res, h * w);
        }

        return res;
         

    }
};
