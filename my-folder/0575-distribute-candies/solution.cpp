class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> st(candyType.begin(), candyType.end());
        int mx = candyType.size() / 2;
        
        return min(mx, int(st.size()));
    }
};
