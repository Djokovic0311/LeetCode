class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1e9+7;
        int result = 0;
        vector<int> cnt (26);
        for(char c : s) {
            cnt[c-'a']++;
        }
        for(int i = 0; i < t; i++) {
            vector<int> next(26);
            next[0] = cnt[25];
            next[1] = (cnt[0] + cnt[25]) % MOD;
            for(int j = 2; j < 26; j++) {
                next[j] = cnt[j-1];
            }
            cnt = next;
        }
        for(int e : cnt) {
            result = (result + e) % MOD;
        }
        return result;
    }
};
