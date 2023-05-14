class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        // Initialize a boolean vector to keep track of friends who received the ball
        vector<bool> received(n, false);
        int current = 0; // Start with the first friend
        received[0] = true;
        for (int i = 1; ; ++i) {
            current = (current + i * k) % n; // Calculate the index of the friend to receive the ball
            if (received[current]) { // If this friend already received the ball, the game ends
                break;
            }

            received[current] = true; // Mark this friend as having received the ball
        }

        vector<int> losers;
        for (int i = 0; i < n; ++i) {
            if (!received[i]) { // If a friend never received the ball, they are a loser
                losers.push_back(i + 1); // Adjust for 1-based indexing
            }
        }

        return losers;       
    }
};
