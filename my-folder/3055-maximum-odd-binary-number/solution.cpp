class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int onesCount = count(s.begin(), s.end(), '1');

        if (onesCount == 1) {
            return string(s.size() - 1, '0') + "1";
        }

        string result(onesCount - 1, '1');
        result += string(s.size() - onesCount, '0');
        result += "1";

        return result;        
    }
};
