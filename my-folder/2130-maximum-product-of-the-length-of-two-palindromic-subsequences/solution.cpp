class Solution {
public:
    bool isPalindrome(const string &s, int mask) {
        string t = "";
        for (int i = 0; i < s.size(); ++i) {
            if (mask & (1 << i)) {
                t += s[i];
            }
        }
        string r = t;
        reverse(r.begin(), r.end());
        return t == r;
    }
    int maxProduct(string s) {
        int n = s.size();
        vector<int> palindromes;

        // Generate all possible palindromic subsequences
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (isPalindrome(s, mask)) {
                palindromes.push_back(mask);
            }
        }

        int maxProduct = 0;

        // Pair each palindrome with all other palindromes
        for (int i = 0; i < palindromes.size(); ++i) {
            for (int j = i + 1; j < palindromes.size(); ++j) {
                if ((palindromes[i] & palindromes[j]) == 0) {  // Check for no overlap
                    int product = __builtin_popcount(palindromes[i]) * __builtin_popcount(palindromes[j]);
                    maxProduct = max(maxProduct, product);
                }
            }
        }

        return maxProduct;        
    }
};
