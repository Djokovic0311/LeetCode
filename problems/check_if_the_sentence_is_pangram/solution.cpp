class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> st(sentence.begin(), sentence.end());
        return st.size() == 26;
    }
};