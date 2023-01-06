class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        int res = 0;
        int n = lights.size();
        map<int,int> mp;
        for(auto l : lights) {
            mp[l[0]-l[1]]++;
            mp[l[1]+l[0]+1]--;
        }

        int curr = 0;
        int mx = INT_MIN;
        int pre = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            curr += it->second;
            if(curr > mx) {
                res = it->first;
                mx = curr;
            }
        }
        return res;
    }
};
