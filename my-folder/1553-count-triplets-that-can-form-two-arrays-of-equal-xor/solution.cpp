class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixXOR(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }
        
        unordered_map<int, int> count, total;
        int result = 0;
        
        for (int k = 0; k < n; ++k) {
            if (count.find(prefixXOR[k + 1]) != count.end()) {
                result += count[prefixXOR[k + 1]] * k - total[prefixXOR[k + 1]];
            }
            count[prefixXOR[k]]++;
            total[prefixXOR[k]] += k;
        }
        
        return result;        
    }
};
