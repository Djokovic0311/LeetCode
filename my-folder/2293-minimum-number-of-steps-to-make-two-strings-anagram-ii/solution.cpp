class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v1(26,0), v2(26,0);
        for(char ch : s) {
            v1[ch-'a']++;
        }
        for(char ch : t) {
            v2[ch-'a']++;
        }
        int res = 0;
        for(int i = 0; i < 26; i++) {
           res += abs(v1[i]-v2[i]); 
        }
        return res;
    }
};
