class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, vector<int>> map;
        //record all scores with corresponding ID
        for(vector<int> v : items) map[v[0]].push_back(v[1]);
        vector<vector<int>> res;
        for(auto& [id, scores] : map) {
            //sort scores in descending order
            sort(scores.rbegin(), scores.rend());
            //calculate the average of the top five scores
            int average = accumulate(scores.begin(), scores.begin() + 5, 0) / 5;
            res.push_back({id, average});
        }
        return res;
        
    }
};