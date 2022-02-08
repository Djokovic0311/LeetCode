class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;
        int n = candies.size();
        vector<bool> res;
        for(int i = 0; i < n; i++) {
            mx = max(mx, candies[i]);
        } 
        for(int i = 0; i < n; i++) {
            res.push_back(candies[i]+extraCandies >= mx);
        }
        return res;
    }
};
