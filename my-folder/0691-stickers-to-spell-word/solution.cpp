class Solution {
public:
    int n, m;
    vector<string> s;
    string t;
    int dp[1<<15];
    int helper(int mask) {
        if(mask == (1<<m)-1) return 0;
        if(dp[mask] != -1) return dp[mask];
        int ans = 1e9;
        for(int i= 0; i <n; i++) {
            vector<int> cnt(26,0);
            for(int j = 0; j < s[i].size(); j++) {
                cnt[s[i][j] - 'a']++;
            }

            int newmask = 0;
            for(int j = 0; j < m; j++) {
                if(!((1<<j) & mask)) {
                    // jth letter not present in the mask
                    if(cnt[t[j]-'a'] > 0) {
                        cnt[t[j]-'a']--;
                        newmask |= (1<<j);
                    }
                }
            }

            if(newmask != 0) ans = min(ans, 1+ helper(mask|newmask));

        }
        return dp[mask] = ans;
    }
    int minStickers(vector<string>& stickers, string target) {
        n = stickers.size();
        m = target.length();
        s = stickers;
        t = target;
        memset(dp,-1,sizeof dp);
        int ans;
        ans = helper(0);
        if(ans >= 1e9) return -1;
        return ans;

    }
};
