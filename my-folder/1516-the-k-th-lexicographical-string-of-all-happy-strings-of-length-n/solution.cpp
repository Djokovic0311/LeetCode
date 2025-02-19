class Solution {
public:
    void generateHappyStrings(int n, string current, vector<string>& happyStrings) {
        if (current.length() == n) {
            happyStrings.push_back(current);
            return;
        }
        
        for (char ch : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != ch) {
                generateHappyStrings(n, current + ch, happyStrings);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        generateHappyStrings(n, "", happyStrings);
        
        return (k <= happyStrings.size()) ? happyStrings[k - 1] : "";        
    }
};
