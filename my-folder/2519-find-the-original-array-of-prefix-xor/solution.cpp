class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res;
        int pre = 0;
        for(int p : pref) {
            res.push_back(p^pre);
            pre = p;
        }
        return res;
    }
};
