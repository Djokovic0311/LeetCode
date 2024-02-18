class Solution {
public:
    // Check if a number is prime
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    // Generate and count prime numbers greater than 10 in one direction
    void generateAndCountPrimes(const vector<vector<int>>& mat, int x, int y, unordered_map<int, int>& freqMap) {
        int m = mat.size(), n = mat[0].size();
        int dirs[8][2] = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}};

        for (auto& dir : dirs) {
            int curX = x, curY = y;
            long num = 0;
            while (curX >= 0 && curX < m && curY >= 0 && curY < n) {
                num = num * 10 + mat[curX][curY];
                if (num > 10 && isPrime(num)) {
                    freqMap[num]++;
                }
                curX += dir[0];
                curY += dir[1];
            }
        }
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        unordered_map<int, int> freqMap;
        int maxFreq = 0;
        int maxFreqPrime = -1;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                generateAndCountPrimes(mat, i, j, freqMap);
            }
        }

        // Find the most frequent and largest prime number
        for (auto& p : freqMap) {
            if (p.second > maxFreq || (p.second == maxFreq && p.first > maxFreqPrime)) {
                maxFreq = p.second;
                maxFreqPrime = p.first;
            }
        }

        return maxFreqPrime == -1 ? -1 : maxFreqPrime;
    }
};
