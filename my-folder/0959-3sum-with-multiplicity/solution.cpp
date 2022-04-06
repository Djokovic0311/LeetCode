class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        map<int,int> mp;
        int n = arr.size();
        // for(int i : arr) mp[i]++;
        int res = 0, mod = 1e9+7;

        for(int i = 0; i < n; i++) {
            res = (res + mp[target - arr[i]]) % mod;
            for(int j = 0; j < i; j++) {
                mp[arr[i] + arr[j]]++;
            }
        }
        return res;
    }
};
