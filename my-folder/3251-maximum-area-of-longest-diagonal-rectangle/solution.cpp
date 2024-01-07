class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal = 0;
        int maxArea = 0;

        for (const auto& dimension : dimensions) {
            int length = dimension[0];
            int width = dimension[1];
            double diagonal = std::sqrt(length * length + width * width);
            int area = length * width;

            // Check if this diagonal is the longest, or if it's equal to the longest but with a larger area
            if (diagonal > maxDiagonal || (diagonal == maxDiagonal && area > maxArea)) {
                maxDiagonal = diagonal;
                maxArea = area;
            }
        }

        return maxArea;
    }
};
