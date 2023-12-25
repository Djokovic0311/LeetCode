class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for(auto w: weights) 
            left = max(left, w), right += w;

        while(left < right) {
            int mid = left + (right - left) / 2;
            int currSize = 0;
            int currDays = 1;
            for(int w : weights) {
                if(w + currSize > mid) {
                    currDays++;
                    currSize = 0;
                }
                currSize += w;
            }

            if(currDays > days) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
