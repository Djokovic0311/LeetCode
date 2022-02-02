class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp = heights;
        sort(tmp.begin(), tmp.end());
        int n = heights.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(heights[i] != tmp[i]) res++;
        }
        return res;
    }
};
