class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int currentWinner = arr[0];
        int consecutiveWins = 0;
        
        // Start from the second element since we already considered the first element as the current winner.
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > currentWinner) {
                // We have a new winner.
                currentWinner = arr[i];
                consecutiveWins = 1; // Reset the consecutive wins because a new winner is found.
            } else {
                // The current winner wins again.
                ++consecutiveWins;
            }
            
            // Check if the current winner has won k consecutive rounds.
            if (consecutiveWins == k) {
                return currentWinner;
            }
        }
        
        // If no one wins k times before the loop ends, then the current winner must be the largest number.
        return currentWinner;        
    }
};
