class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int res = 0;
        res += (abs(ay2-ay1) * abs(ax2-ax1)) + (abs(by1-by2) * abs(bx1-bx2));
        vector<int> x = {ax1, ax2, bx1, bx2};
        vector<int> y = {ay1, ay2, by1, by2};
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if(ax2 <= bx1 || bx2 <= ax1 || ay2<=by1|| by2 <= ay1)
            return res;
        else return res - (abs(x[1]-x[2]) * abs(y[1]-y[2]));
        
    }
};
