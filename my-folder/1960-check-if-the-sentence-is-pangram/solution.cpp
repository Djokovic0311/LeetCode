class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> s;
        for(auto ch:sentence) {
            s.insert(ch);
        }
        return s.size()==26;
    }
};
