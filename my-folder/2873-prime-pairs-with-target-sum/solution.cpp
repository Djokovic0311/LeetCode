class Solution {
private:
    bool isPrime(int num) {
        if(num <= 1) {
            return false;
        }
        for(int i = 2; i * i <= num; ++i) {
            if(num % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> result;
        for(int i = 2; i <= n/2; ++i) {
            if(isPrime(i) && isPrime(n - i)) {
                result.push_back({i, n - i});
            }
        }
        return result;        
    }
};
