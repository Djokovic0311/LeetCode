class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int k = n/4, res = n, i = 0;
        for(char c : s)
            mp[c]++;
        for(int j = 0; j < n; j++) {
            mp[s[j]]--;
            while(i < n && mp['Q'] <= k && mp['W'] <= k && mp['R'] <= k && mp['E'] <= k){
                res = min(res, j-i+1);
                mp[s[i++]]++;
            }
            
        }
        return res;
    }
};