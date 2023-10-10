class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int i = 0, len = num.size();
        
        // Find the first digit that violates the monotonic increasing condition
        while (i + 1 < len && num[i] <= num[i + 1]) {
            i++;
        }
        
        if (i + 1 < len) {
            // Decrement the digit
            num[i]--;
            // Set all the digits to its right to 9
            for (int j = i + 1; j < len; j++) {
                num[j] = '9';
            }
            
            // Handle the special condition where decrementing might cause the number to be non-monotonic
            while (i > 0 && num[i] < num[i - 1]) {
                num[i - 1]--;
                num[i] = '9';
                i--;
            }
        }
        
        return stoi(num);        
    }
};
