class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int ans = 0, hPrev = 1, hCount = 1, hMax = 1, vPrev = 1, vCount = 1, vMax = 1;
        for(int i = 0; i < hBars.size(); ++i) {
            if(hPrev+1 == hBars[i]){
                hCount++;
            }else{
                hCount = 2;
            }
            hPrev = hBars[i];
            hMax = max(hMax, hCount);
        }
        for(int i = 0; i < vBars.size(); ++i) {
            if(vPrev+1 == vBars[i]){
                vCount++;
            }else{
                vCount = 2;
            }
            vPrev = vBars[i];
            vMax = max(vMax, vCount);
        }
        return min(hMax, vMax) * min(hMax, vMax);
    }

};
