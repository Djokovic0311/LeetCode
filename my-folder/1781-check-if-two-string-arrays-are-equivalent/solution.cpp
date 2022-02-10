class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        int i2 = 0, j2 = 0, lmt2 = w2.size();
        for (string chunk1: w1) {
            for (char c: chunk1) {
                if (i2 == lmt2 || c != w2[i2][j2++]) return false;
                // updating w2 pointers
                if (j2 == w2[i2].size()) {
                    i2++, j2 = 0;
                }
            }
        }
        return i2 == lmt2;
    }
};
