class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1, res = 0;
        int tmp = 0;
        while(i < j) {
            if(height[i] <= height[j]) {
                tmp = (j-i) * height[i];
                i++;
            }
            else {
                tmp = (j-i) * height[j];
                j--;
            }
            res = max(res, tmp);
        }
        return res;
    }
};
