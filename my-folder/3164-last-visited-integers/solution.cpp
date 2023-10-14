class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> visitedIntegers;
        vector<int> result;

        int consecutivePrevCount = 0;
        for (const auto& word : words) {
            if (word == "prev") {
                consecutivePrevCount++;

                // Check if the consecutivePrevCount is more than the number of visited integers
                if (consecutivePrevCount > visitedIntegers.size()) {
                    result.push_back(-1);
                } else {
                    result.push_back(visitedIntegers[visitedIntegers.size() - consecutivePrevCount]);
                }
            } else {
                // Reset the count of consecutive "prev" strings
                consecutivePrevCount = 0;

                // Append the current integer to the list of visited integers
                visitedIntegers.push_back(stoi(word));
            }
        }

        return result;        
    }
};
