class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int res = 0;
        int left_max = 0, right_max = 0;
        while(left < right) {
            if(height[left]  > left_max) left_max = height[left];
            if(height[right] > right_max) right_max = height[right];
            // cout << left <<  " " << right << " " << left_max << " " << right_max << endl;
            if(left_max < right_max) {
                res += left_max - height[left];
                // cout << "left " <<left << endl;
                left++;
            } else {
                res += right_max - height[right];
                // cout << "right " <<right << endl;
                right--;
            }
        }

        return res;
    }
};


