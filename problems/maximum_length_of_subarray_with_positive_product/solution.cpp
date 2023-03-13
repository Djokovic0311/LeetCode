class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int posLen = 0, negLen = 0, maxLen = 0;
        for (int i : nums) {
            // cout << posLen << " " << negLen << endl;
            if (i == 0) posLen = 0, negLen = 0;
            else {
                if (i < 0) swap(posLen, negLen);
                if (posLen > 0 || i > 0) ++posLen;
                if (negLen > 0 || i < 0) ++negLen;
                maxLen = max(maxLen, posLen);
            }
        }
        return maxLen;
    }
};