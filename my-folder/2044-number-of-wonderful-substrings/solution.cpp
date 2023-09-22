class Solution {
public:
    long long wonderfulSubstrings(std::string word) {
        unordered_map<int, int> count = {{0, 1}};  // Initialize with empty string
        int mask = 0;
        long long res = 0;
        
        for (char c : word) {
            mask ^= (1 << (c - 'a'));  // Flip the corresponding bit for character c
            
            res += count[mask];  // Current substring itself is wonderful
            
            // Check for substrings where only one character has odd occurrences
            for (int i = 0; i < 10; ++i) {
                res += count[mask ^ (1 << i)];
            }
            
            count[mask]++;  // Increase the frequency for current mask
        }
        
        return res;
    }
};
