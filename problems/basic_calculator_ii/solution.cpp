class Solution {
public:
    int calculate(string s) {
        // support variables
        int n = 0, i = 0, len = s.size();
        bool minus = false, multi = false;
        vector<int> tmp;
        // moving len right after the last valid character
        while (s[len - 1] == ' ') len--;
        // main parsing loop
        while (i < len) {
            // ignoring spaces
            while (i < len && s[i] == ' ') i++;
            // parsing numbers
            while (i < len && s[i] >= '0' && s[i] <= '9') {
                n = n * 10 + (s[i] - '0');
                i++;
            }
            // updating tmp and resetting n
            tmp.push_back(minus ? -n : n);
            n = 0;
            // ignoring spaces - again
            while (i < len && s[i] == ' ') i++;
            // handling multiplications/divisions/end of parsing
            while (i < len && (s[i] == '*' || s[i] == '/')) {
                multi = s[i] == '*';
                i++;
                // ignoring spaces - again and again
                while (i < len && s[i] == ' ') i++;
                while (i < len && s[i] >= '0' && s[i] <= '9') {
                    n = n * 10 + (s[i] - '0');
                    i++;
                }
                // updating tmp and resetting n
                tmp.back() = multi ? tmp.back() * n : tmp.back() / n;
                n = 0;
                // ignoring spaces - again and again and again
                while (i < len && s[i] == ' ') i++;
            }
            // preparing for the next loop
            minus = s[i] == '-';
            i++;
        }
        return accumulate(begin(tmp), end(tmp), 0);
    }
};