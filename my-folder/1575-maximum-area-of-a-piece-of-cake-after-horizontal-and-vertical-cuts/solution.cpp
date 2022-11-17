class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.insert(horizontalCuts.begin(),0);
        horizontalCuts.push_back(h);
        verticalCuts.insert(verticalCuts.begin(), 0);
        verticalCuts.push_back(w);
        int mod = 1e9 + 7;
        int mx1 = 0, mx2 = 0;
        for(int i = 1;i < horizontalCuts.size(); i++) {
            mx1 = max(horizontalCuts[i]-horizontalCuts[i-1], mx1);
        }
        for(int i = 1;i < verticalCuts.size(); i++) {
            mx2 = max(verticalCuts[i]-verticalCuts[i-1], mx2);
        }
        return (long long)mx1 * (long long)mx2 % mod;
    }
};
