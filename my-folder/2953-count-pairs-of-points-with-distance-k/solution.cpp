class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
    unordered_set<string> coord_set;
    unordered_map<string,long long> freq;
    // Convert the 2D point into a unique string for easy storage and lookup
    auto coordToKey = [](int x, int y) -> string {
        return to_string(x) + "," + to_string(y);
    };

    // Precompute the XOR frequency for x and y coordinates and populate the set
    for (const vector<int>& point : coordinates) {
        int x = point[0];
        int y = point[1];
        coord_set.insert(coordToKey(x, y));
        freq[coordToKey(x, y)]++;
    }

    long long count = 0;
    for (const vector<int>& point : coordinates) {
        int x1 = point[0];
        int y1 = point[1];
        // cout << x1 << " " << y1 << endl;
        
        // Deduct the current point from the frequency map
        // x_freq[x1]--;
        // y_freq[y1]--;
        freq[coordToKey(x1, y1)]--;
        for (int d_x = 0; d_x <= k; ++d_x) {
            int d_y = k - d_x;
            int x2 = x1 ^ d_x;
            int y2 = y1 ^ d_y;
            // cout << x2 << " " <<y2 <<endl;
        
            // Check if (x2, y2) is in the original coordinates and if it forms a valid pair
            if (coord_set.find(coordToKey(x2, y2)) != coord_set.end()) {
                count += freq[coordToKey(x2, y2)];
            }
            // cout << count << endl;
        }
        // cout << endl;
        // Add the current point back to the frequency map
        // x_freq[x1]++;
        // y_freq[y1]++;
        freq[coordToKey(x1, y1)]++;
    }

    // Since each pair is counted twice (i, j) and (j, i), divide the result by 2
    return count / 2;
    }
};
