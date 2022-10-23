class Solution {
public:
    int subarrayGCD(vector<int>& arr, int k) {
        // To store the final answer
        int ans = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {

            // To store the GCD starting from
            // index 'i'
            int curr_gcd = 0;

            // Loop to find the gcd of each subarray
            // from arr[i] to arr[i...n-1]
            for (int j = i; j < n; j++) {
                curr_gcd = __gcd(curr_gcd, arr[j]);

                // Increment the count if curr_gcd = 1
                ans += (curr_gcd == k);
            }
        }

        // Return the final answer
        return ans;        
    }
};