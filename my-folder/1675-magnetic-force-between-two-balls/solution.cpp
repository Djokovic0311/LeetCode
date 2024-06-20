class Solution {
public:
    bool canPlaceBalls(const vector<int>& position, int m, int minForce) {
        int count = 1; // Place the first ball
        int lastPos = position[0];
        
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - lastPos >= minForce) {
                count++;
                lastPos = position[i];
            }
            if (count >= m) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        // Sort the positions to apply binary search
        sort(position.begin(), position.end());
        
        int left = 1; // The minimum possible force
        int right = position.back() - position.front(); // The maximum possible force
        
        int result = 0;
        
        // Binary search to find the maximum minimum force
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canPlaceBalls(position, m, mid)) {
                result = mid; // Update result as mid is a valid force
                left = mid + 1; // Try for a larger minimum force
            } else {
                right = mid - 1; // Try for a smaller minimum force
            }
        }
        
        return result;
    }
};
