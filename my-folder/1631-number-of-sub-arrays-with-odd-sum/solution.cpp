class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int result = 0;
        // the number of even/odd subarray ending at position i
        int n = arr.size();
        vector<int> even(n, 0), odd(n, 0);
        if(arr[n-1] % 2 == 0) {
            even[n-1] = 1;
        } else {
            odd[n-1] = 1;
        }

        for(int i = n-2; i >= 0; i--) {
            if(arr[i] % 2 == 1) {
                odd[i] = (1 + even[i+1]) % MOD;
                even[i] = odd[i+1];
            } else {
                even[i] = (1 + even[i+1]) % MOD;
                odd[i] = odd[i+1];
            }
        }
        for(int i = 0; i < n; i++) {
            result = (odd[i] + result) % MOD;
        }

        return result;
    }
};
