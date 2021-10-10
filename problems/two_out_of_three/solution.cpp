class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> res;
        unordered_map<int, int> mp;
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());
        set<int> st3(nums3.begin(), nums3.end());
        for(set<int>::iterator it = st1.begin(); it != st1.end(); it++) {
            mp[*it] = 1;
        }
        for(set<int>::iterator it = st2.begin(); it != st2.end(); it++) {
            if(mp.find(*it) != mp.end()) {
                mp[*it] = 2;
            }
            else mp[*it] = 1;
        }
        for(set<int>::iterator it = st3.begin(); it != st3.end(); it++) {
            if(mp.find(*it) != mp.end()) {
                mp[*it]++;
            }
            
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            // cout << it->first << ' ' << it->second << endl;
            if(it->second > 1) res.push_back(it->first);
        }
        return res;
    }
};