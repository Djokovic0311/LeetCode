class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 1;
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i : arr)
            res = max(res, mp[i] = 1+mp[i-difference]);
        return res;
    }
};