class Solution {
public:
    int maxPossibleLen = 0;
    void checkCombination(vector<string> arr, int start, string &res) {
        if (res.length() > maxPossibleLen)
            maxPossibleLen = res.length();
        if (start == arr.size())
            return;
        for (int i = start; i < arr.size(); i++) {
            string temp = res + arr[i];
            bool mask[27] = {false};
            for (char c: res)
                mask[c-'a'] = true;
            bool unique_chars = true;
            for (char c: arr[i]) {
                if (mask[c-'a']) {
                    unique_chars = false;
                    break;
                }
                mask[c-'a'] = true;
            }
            if (unique_chars)
                checkCombination(arr, i + 1, temp);
        }
    }
    int maxLength(vector<string>& arr) {
        string res;
        checkCombination(arr, 0, res);
        return maxPossibleLen;
    }
};
