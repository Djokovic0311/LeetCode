class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (auto num : arr) freq[num]++;
        
        sort(arr.begin(), arr.end());
        
        for (auto num : arr) {
            if (freq[num] && freq[num*2]) {
                freq[num]--;
                freq[num*2]--;
            }
        }
        
        for (auto [a, b] : freq)
            if (b) return false;
        
        return true;        
    }
};