class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int vowels[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
        int i = 0, j;
        int mx = 0, cur=0;
        for(j = 0; j < n; j++) {
            // int cur = 0;
            cur += vowels[s[j]-'a'];
            if(j >= k)
                cur -= vowels[s[j-k]-'a'];
            mx = max(mx, cur);
        }
        return mx;
    }
};
