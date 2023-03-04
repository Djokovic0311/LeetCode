class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        const int MOD = 1e9 + 7;
        int n = ranges.size();
        vector<vector<vector<int>>> groups;
        sort(ranges.begin(), ranges.end());
        groups.push_back({ranges[0]});
        int j = 0;
        int end = ranges[0][1];
        long long res = 1;
        
         for (int i = 1; i < n; i++) {
            if (ranges[i][0] <= end) {
              if (ranges[i][1] > end) {
                end = ranges[i][1];
              }
              groups[j].push_back(ranges[i]);
            } else {
              groups.push_back({ranges[i]});
              j++;
              end = ranges[i][1];
            }
        }
        
        int sz = groups.size();
        
        while(sz) {
            res = res * 2 % MOD;
            sz--;
        }
        return (int)res;

    }
};
