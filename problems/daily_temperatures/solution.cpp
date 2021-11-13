class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty())
        {
            return vector<int>();
        }
        stack<pair<int, int>> s;

        s.push(make_pair(T.back(), 0));
        
        vector<int> ans(T.size(), 0);
        
        for (int i = T.size() - 2; i >= 0; i--)
        {
            int counter = 1;
            
            while (!s.empty() && T[i] >= s.top().first)
            {
                counter += s.top().second;
                s.pop();
            }
            
            if (s.empty())
            {
                s.push(make_pair(T[i], 0));
            }
            else
            {
                s.push(make_pair(T[i], counter));
                ans[i] = counter;
            }
        }
        
        return ans;
    }
};