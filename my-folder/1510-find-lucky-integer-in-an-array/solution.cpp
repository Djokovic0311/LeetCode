class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            mp[arr[i]] ++;
        }
        int res = -1;
        for(auto it = mp.begin();  it!= mp.end(); it++) {
            if(it->first == it->second) res = max(res, it->first);
        }
        return res;
    }
};
