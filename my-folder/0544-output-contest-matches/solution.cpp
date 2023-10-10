class Solution {
public:
    string findContestMatch(int n) {
    vector<string> matches;
    for (int i = 1; i <= n; i++) {
        matches.push_back(to_string(i));
    }
    
    while (matches.size() > 1) {
        vector<string> newRound;
        for (int i = 0; i < matches.size() / 2; i++) {
            newRound.push_back("(" + matches[i] + "," + matches[matches.size() - 1 - i] + ")");
        }
        matches = newRound;
    }
    
    return matches[0];       
    }
};
