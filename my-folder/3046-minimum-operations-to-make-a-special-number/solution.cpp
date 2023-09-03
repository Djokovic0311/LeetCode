class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        
        // If there's a '0' in the number, try to delete all other characters to get to that '0'
        int singleZeroOps = n;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                singleZeroOps = min(singleZeroOps, n - 1);
            }
        }

        // set a large default value for operations required for each pattern
        int best = n + 1;
        // Iterate for each pattern: 00, 25, 50, 75
        vector<string> patterns = {"00", "25", "50", "75"};
        for (string pat : patterns) {
            int lastIdx = -1, secondLastIdx = -1;
            // try to find the last occurrence of the second digit and
            // the closest previous occurrence of the first digit
            for (int i = n - 1; i >= 0; i--) {
                if (num[i] == pat[1] && lastIdx == -1) {
                    lastIdx = i;
                } else if (num[i] == pat[0] && lastIdx != -1) {
                    secondLastIdx = i;
                    break;
                }
            }
            // if both indices are found, update the answer
            if (secondLastIdx != -1 && lastIdx != -1) {
                int ops = n - lastIdx - 1;  // digits after last index
                ops += (lastIdx - secondLastIdx - 1);  // digits between the two indices
                best = min(best, ops);
            }
        }
        return min(best, singleZeroOps);
    }
};

