class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == key && i < n-1) {
                m[nums[i+1]]++;
            }
        }
        int mx = 0;
        int res = -1;
        for(auto iter = m.begin(); iter != m.end(); iter++) {
            if(iter->second > mx) {
                mx = iter->second;
                res = iter->first;
            }
        }
        return res;
    }
};