#define ll long long
class Solution {
public:
    ll dp[10001][11][11][6];
    ll mod;
    ll dfs(int ind, int first, int second, int i, string &s) {
        if(i == 5) return 1; //found a subsequence
        if(ind == s.length()) return 0;
        if(dp[ind][first][second][i] != -1) return dp[ind][first][second][i];
        
        //option of not choosing current digit
        long long res = dfs(ind + 1, first, second, i, s);

        if(i == 0) {
            //option of choosing the first digit of the subsequence
            res += dfs(ind + 1, s[ind] - '0', second, i + 1, s);
            res %= mod;
        } else if(i == 1) {
            //option of choosing the second digit of the subsequence
            res += dfs(ind + 1, first, s[ind] - '0', i + 1, s);
            res %= mod;
        } else if(i == 2) {
            //option of choosing the third digit of the subsequence
            res += dfs(ind + 1, first, second, i + 1, s);
            res %= mod;
        } else if(i == 3) {
            //option of choosing the fourth digit of the subsequence if it matches with the second digit
            if(s[ind] - '0' == second) {
                res += dfs(ind + 1, first, second, i + 1, s);
                res %= mod;
            }
        } else if(i == 4) {
            //option of choosing the fifth digit of the subsequence if it matches with the first digit
            if(s[ind] - '0' == first) {
                res += dfs(ind + 1, first, second, i + 1, s);
                res %= mod;
            }
        }
        return dp[ind][first][second][i] = res;
    }
    int countPalindromes(string s) {
        memset(dp, -1, sizeof dp); 
        mod = 1e9 + 7;
        return dfs(0, 10, 10, 0, s);
    }
};
