class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        if(n == 0 || days == 0) return 0;
        int left = INT_MIN, right;
        for(int weight : weights) {
            left = max(weight, left);
            right += weight;
        }
        while(left < right) {
            int mid = left + (right - left) / 2;
            int curdays = 1, curbag = 0;
            for(int weight : weights) {
                if(curbag+weight > mid) {
                    curdays++;
                    curbag = 0;
                }
                curbag += weight;
            }
            if(curdays > days) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};