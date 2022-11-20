class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int l = 0, r = n-1;
        while(l < r) {
            res = max(res, (r-l) * min(height[r], height[l]));
            if(height[l] < height[r])
                l++;
            else r--;
        }
        return res;        
    }
};