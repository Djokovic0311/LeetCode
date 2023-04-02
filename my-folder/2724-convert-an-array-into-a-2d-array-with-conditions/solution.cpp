class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        unordered_set<int> s;
        unordered_map<int,int> mp;
        
        for(int num : nums) mp[num]++, s.insert(num);
        
        while(!s.empty()) {
            vector<int> row;
            row.assign(s.begin(), s.end());
            // for(auto r : row) cout << r << " ";
            // cout << endl;
            res.push_back(row);
            // cout << res.size() <<endl;
            for(int item : row) {
                // cout << item << " ";
                mp[item]--;
                if(mp[item] == 0) {
                    s.erase(item);
                }
            }
        }
        
        return res;
    }
};
