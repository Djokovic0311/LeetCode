class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int res = 0;
        int n = baskets.size();
        for(int f : fruits) {
            int unplaced = 1;
            for(int i = 0; i < n; i++) {
                if(f <= baskets[i]) {
                    baskets[i] = 0;
                    unplaced = 0;
                    break;
                }
            }
            res += unplaced;
        }
        return res;
    }
};
