class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        if(weights.empty() || days == 0) return 0;
        int left = 0, right = 0;
        for(auto w: weights) left = max(left, w), right += w;
        if(days == weights.size()) return left;
        while(left < right) {
            int mid = (left + right) / 2;
            int curr_days = 1, curr_bagsize = 0;
            for(auto w : weights) {
                if(curr_bagsize + w > mid) { 
                    curr_days++; curr_bagsize = 0;
                }
                curr_bagsize += w;
            }
            if(curr_days > days) left = mid + 1; //we need bigger bag sizes to accomodate
            else right = mid; 
        }
        return left;        
    }
};
