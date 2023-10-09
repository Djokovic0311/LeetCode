class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        int res = r;
        while(l < r) {
            int ops = 0;
            int mid = (r-l)/2 + l;
            for(int num : nums) {
                if(num > mid) {
                    if(num % mid == 0) {
                        ops += num / mid -1;
                    } else {
                        ops += num / mid;
                    }
                }
            }

            if(ops > maxOperations) {
                l = mid +1;
            }
            else {
                r = mid;
                res = mid;
            }
        }

        return res;
    }
};
