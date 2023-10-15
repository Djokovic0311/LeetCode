class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int ones = 0; // Count of 1's in the current substring
        string result = ""; // The result string
        int minLength = n + 1; // The length of the shortest beautiful substring

        for (int i = 0, j = 0; j < n; ++j) {
            if (s[j] == '1') {
                ones++;
            }

            // If the current substring has k ones, then update the result
            while (ones == k) {
                int len = j - i + 1;

                // Update the result string and minLength
                if (len < minLength) {
                    minLength = len;
                    result = s.substr(i, len);
                } else if (len == minLength) {
                    string sub = s.substr(i, len);
                    result = min(result, sub);
                }

                if (s[i] == '1') {
                    ones--;
                }
                i++;
            }
        }
        return result;        
    }
};
