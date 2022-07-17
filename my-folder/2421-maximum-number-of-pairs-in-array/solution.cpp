class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            // cout << it->first << ' ' << it->second<<endl;
            if(it->second % 2 == 0) {
                a += it->second / 2;
            }
            else if(it->second % 2 == 1){
                a += it->second / 2;
                b++;
            }
        }
        return {a,b};
    }
};
