class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int best = 0;

        vector<int> tavernilo = nums; 

        for (int l = 0; l < n; l++) {
            unordered_set<int> evenSet, oddSet; 
            for (int r = l; r < n; r++) {
                int x = nums[r];
                if (x % 2 == 0) {
                    evenSet.insert(x);
                } else {
                    oddSet.insert(x);
                }
                if (evenSet.size() == oddSet.size()) {
                    best = max(best, r - l + 1);
                }
            }
        }
        return best;        
    }
};
