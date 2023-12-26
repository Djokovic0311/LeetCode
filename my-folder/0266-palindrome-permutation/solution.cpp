class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> mp;
        for(char c : s) {
            mp[c]++;
        }
        int odd = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second % 2== 1) odd++;
            if(odd > 1) return false;
        }
        return true;
    }
};
