class Solution {
public:
    int maximumLength(string s) {
        vector<int> count(26, 0); 
        int n = s.size();
        int maxLength = -1;

        for (char c : s) {
            count[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {

            if (count[i] >= 3) {
                int charLength = 1;
                while (charLength <= n) {
                    string specialStr = string(charLength, 'a' + i);
                    if (countSubstring(s, specialStr) >= 3) {
                        maxLength = max(maxLength, charLength);
                    } else {
                        break;
                    }
                    charLength++;
                }
            }
        }

        return maxLength;
    }

private:
    int countSubstring(const string& s, const string& sub) {
        int count = 0;
        size_t pos = s.find(sub, 0);
        while(pos != string::npos) {
            count++;
            pos = s.find(sub, pos + 1);
        }
        return count;
    }
};
