class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        int n = list1.size();
        int m = list2.size();
        for(int i = 0; i < n; i++) {
            mp[list1[i]] = i;
        }
        vector<string> res;
        int min_idx = INT_MAX;
        for(int j = 0; j < m; j++) {
            if(mp.find(list2[j]) != mp.end()) {
                int tmp = j + mp[list2[j]];
                if(tmp == min_idx)
                    res.push_back(list2[j]);
                if(tmp < min_idx) {
                    min_idx = tmp;
                    res.clear();
                    // vector<int> res;
                    res.push_back(list2[j]);
                }

            }
        }
        return res;
    }
};