class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> res(2,vector<int>());
        for(int i = 0; i < n1; i++) {
            mp[nums1[i]] = 1;
        }
        for(int i = 0; i < n2;i++) {
            if(mp.find(nums2[i]) == mp.end()) res[1].push_back(nums2[i]);
            else mp[nums2[i]] = 2;
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second == 1) res[0].push_back(it->first);
        }
        for(int i =0; i < 2; i++){
                set<int>s(res[i].begin(), res[i].end());
                res[i].assign(s.begin(), s.end());
        }
        return res;
    }
};