class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n, 0);
        unordered_map<int, int> colors; // idx <-> color
        unordered_map<int, int> color_count; // number of ball of each color
        int distinct = 0;

        for(int i = 0; i < n; i++) {
            int idx = queries[i][0], newColor = queries[i][1];
            int oldColor = colors[idx];
            if(oldColor != 0) {
                color_count[oldColor]--;
                if(color_count[oldColor] == 0) {
                    distinct--;
                }
            }
            if(color_count[newColor] == 0) {
                distinct++;
            } 
            color_count[newColor]++;    
            colors[idx] = newColor;
            result[i] = distinct;
        }

        return result;
    }
};
