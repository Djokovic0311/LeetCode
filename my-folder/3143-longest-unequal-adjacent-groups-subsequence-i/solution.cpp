class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
            // Resultant list of words.
        std::vector<std::string> result;

        // Check if groups is empty.
        if (groups.empty()) {
            return result;
        }

        // Initialize with the first group.
        int currentGroup = groups[0];
        result.push_back(words[0]);

        // Iterate over the groups.
        for (int i = 1; i < groups.size(); ++i) {
            if (groups[i] != currentGroup) {
                result.push_back(words[i]);
                currentGroup = groups[i];
            }
        }

        return result;
    }
};
