class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1,1}};
        vector<vector<int>> results;
        results.push_back({1});
        results.push_back({1,1});
        for(int i = 3; i <= numRows; i++){
            vector<int> tmp;
            tmp.push_back(1);
            for(int j = 0; j < i-2; j++){
                tmp.push_back(results[i-2][j] + results[i-2][j+1]);
            }
            tmp.push_back(1);    
            results.push_back(tmp);
        }
        return results;
    }
};