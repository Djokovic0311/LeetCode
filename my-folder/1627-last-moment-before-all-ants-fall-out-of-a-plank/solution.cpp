class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int maxTime = 0;

    // Compute maximum time for ants moving to the left
    for (int pos : left) {
        maxTime = std::max(maxTime, pos);
    }

    // Compute maximum time for ants moving to the right
    for (int pos : right) {
        maxTime = std::max(maxTime, n - pos);
    }

    return maxTime;        
    }
};
