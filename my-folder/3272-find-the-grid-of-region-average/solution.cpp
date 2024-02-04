class Solution {
public:

    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m = image.size(), n = image[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        vector<vector<int>> count(m, vector<int>(n, 0)); // To hold counts for averaging

        // Lambda to check if a 3x3 region is valid based on the threshold
        auto isValidRegion = [&](int x, int y) {
            for (int i = x; i < x + 3; ++i) {
                for (int j = y; j < y + 3; ++j) {
                    if (i > x && abs(image[i][j] - image[i - 1][j]) > threshold) return false;
                    if (j > y && abs(image[i][j] - image[i][j - 1]) > threshold) return false;
                }
            }
            return true;
        };

        // Iterate through each possible top-left corner of a 3x3 region
        for (int i = 0; i <= m - 3; ++i) {
            for (int j = 0; j <= n - 3; ++j) {
                if (isValidRegion(i, j)) {
                    int sum = 0;
                    for (int x = i; x < i + 3; ++x) {
                        for (int y = j; y < j + 3; ++y) {
                            sum += image[x][y];
                            count[x][y]++;
                        }
                    }
                    int avg = sum / 9;
                    for (int x = i; x < i + 3; ++x) {
                        for (int y = j; y < j + 3; ++y) {
                            result[x][y] += avg;
                        }
                    }
                }
            }
        }

        // Calculate final averages for each pixel
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = count[i][j] ? result[i][j] / count[i][j] : image[i][j];
            }
        }

        return result;      
    }
};
