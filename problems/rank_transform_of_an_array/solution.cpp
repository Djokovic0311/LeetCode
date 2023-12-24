class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(),arr.end());
        unordered_map<int,int> m;
        int rank=1;
        for(auto &i: st)  m[i]=rank++;
        for(auto &i: arr) i = m[i];
        return arr;
    }
};