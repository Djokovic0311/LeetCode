// #include <numric>
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            long long int curr_lcm = 1;

            // Loop to find the gcd of each subarray
            // from arr[i] to arr[i...n-1]
            for (int j = i; j < n; j++) {
                curr_lcm = std::lcm(curr_lcm, (long long)(nums[j]));
                if(curr_lcm > k) break;
                // cout << curr_lcm;
                res += (curr_lcm == k);
            }
        }        
        return res;
    }
};