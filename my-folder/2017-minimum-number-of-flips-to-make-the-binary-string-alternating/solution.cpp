class Solution {
public:

    int minFlips(string s) {
        int n = s.size();
        int total = 2 * n;  // Two copies of s to simulate rotation

        // Store the total flip counts for both patterns at each rotation
        int ans1 = 0, ans2 = 0;

        // Final result
        int ans = INT_MAX;

        for (int i = 0; i < total; i++) {
            // Update flip counts based on current character
            if (s[i % n] == (i % 2 == 0 ? '0' : '1')) ans1++;
            if (s[i % n] == (i % 2 == 0 ? '1' : '0')) ans2++;

            // Once we've covered the length of s, we have one rotation's result
            if (i >= n) {
                // Remove the effect of the first character of the rotation
                if (s[(i - n) % n] == ((i - n) % 2 == 0 ? '0' : '1')) ans1--;
                if (s[(i - n) % n] == ((i - n) % 2 == 0 ? '1' : '0')) ans2--;
            }

            // Update the final result if we've covered at least the length of s
            if (i >= n - 1) {
                ans = min(ans, min(ans1, ans2));
            }
        }

        return ans;    
    }
};
