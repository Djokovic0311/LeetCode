class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        vector<int> res(n);
        if(n == 1) return res;
        for(int i = n-1; i>=0; i--) {
            int cnt = 1;
            while(!stk.empty() && heights[stk.top()] <= heights[i]) {
                stk.pop();
                cnt++;
            }
            if(stk.empty()) cnt--;
            res[i] = cnt;
            stk.push(i);
        }
        return res;
    }
};
