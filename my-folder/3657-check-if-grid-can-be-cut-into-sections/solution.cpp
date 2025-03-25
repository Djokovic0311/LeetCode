class Solution {
public:
    bool checkByDimension(vector<vector<int>>& rectangles, int dim) {
        int cuts = 0;
        int farthestEnd = 0;
        sort(rectangles.begin(), rectangles.end(), [dim](const vector<int>& a, const vector<int>& b) {
            return a[dim] < b[dim];
        });

        for(auto rec : rectangles) {
            if(farthestEnd <= rec[dim] && farthestEnd != 0) {
                cuts++;
            }
            farthestEnd = max(farthestEnd, rec[dim+2]);
        }

        return cuts >= 2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return checkByDimension(rectangles, 0) || checkByDimension(rectangles, 1);
    }
};
