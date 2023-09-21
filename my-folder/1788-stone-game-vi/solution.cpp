class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    int n = aliceValues.size();
    // Create pairs of (value difference, index)
    std::vector<std::pair<int, int>> diff;
    for (int i = 0; i < n; i++) {
        diff.push_back({aliceValues[i] + bobValues[i], i});
    }
    // Sort based on the difference in descending order.
    std::sort(diff.begin(), diff.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first > b.first;
    });
    
    int aliceScore = 0, bobScore = 0;
    for (int i = 0; i < n; i++) {
        // If it's Alice's turn
        if (i % 2 == 0) {
            aliceScore += aliceValues[diff[i].second];
        } else { // If it's Bob's turn
            bobScore += bobValues[diff[i].second];
        }
    }
    
    if (aliceScore == bobScore) return 0;
    if (aliceScore > bobScore) return 1;
    return -1;        
    }
};
