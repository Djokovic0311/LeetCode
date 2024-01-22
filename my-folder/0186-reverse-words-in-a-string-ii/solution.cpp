class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int start = 0, end = 0;
        while(end < n) {
            while(end < n && s[end] != ' ') {
                end++;
            }

            int ts = start, te = max(end-1, start);

            while(ts < n && te < n && ts < te) {
                swap(s[ts], s[te]);
                ts++;
                te--;
            }
            end++;
            start = end;
        }
    }
};
