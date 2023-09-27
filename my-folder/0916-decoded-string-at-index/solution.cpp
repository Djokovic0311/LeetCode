class Solution {
public:
    std::string decodeAtIndex(std::string s, int k) {
        long long len = 0;
        int n = s.size();
        
        // Compute the length of the decoded string.
        for(char c : s) {
            if(isdigit(c)) {
                cout << len <<endl;
                len *= (c - '0');
            } else {
                len++;
            }
        }
        for (int i = n-1; i >=0; --i) {
            k %= len;
            if (k == 0 && isalpha(s[i]))
                return (string) "" + s[i];

            if (isdigit(s[i]))
                len /= s[i] - '0';
            else
                len--;
        }

        return "";  // Should never reach here.
    }
};
