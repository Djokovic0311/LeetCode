class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int mx = 0;
        int n = heights.size();
        vector<int> res;

        for(int i = n-1; i>= 0; i--) {
            if (res.empty() || heights[i] > heights[res.back()])
                res.push_back(i);
                
            
        }
        return vector<int>(rbegin(res), rend(res));
    }
};
