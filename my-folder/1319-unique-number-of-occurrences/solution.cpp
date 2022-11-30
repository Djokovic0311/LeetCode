class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i =0; i < n; i++) {
            mp[arr[i]]++;
        }
        vector<int> res;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            res.push_back(it->second);
        }
        int l1 = res.size();
        set<int> st(res.begin(), res.end());
        int l2 = st.size();
        return l1 == l2;        
    }
};
