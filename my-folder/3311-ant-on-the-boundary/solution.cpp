class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int position = 0; // Starting at the boundary
        int returnToBoundaryCount = 0;

        for (int num : nums) {
            position += num; // Move the ant based on the current number
            if (position == 0) {
                // The ant has returned to the boundary
                returnToBoundaryCount++;
            }
        }

        return returnToBoundaryCount;        
    }
};
