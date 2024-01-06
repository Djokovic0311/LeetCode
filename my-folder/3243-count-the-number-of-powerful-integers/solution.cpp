using ll = long long;

class Solution {
private:
    string x;
    int lim;
    ll dp[17][2][2];
    ll rec(int ind, int tight, int isSuff, string &ss){
        // if range string's size < suffix, no valid numbers
        if(ss.size() < x.size())return 0;
        int n = ss.size();
        // base case
        if(ind == n)
            return isSuff;
        
        if(~dp[ind][tight][isSuff])return dp[ind][tight][isSuff];
        // highest digit range
        int hi = tight ? ss[ind] - '0' : lim;
        ll ans = 0;
        for(int i=0; i<=hi && i<=lim; ++i){
            // check if suffix is valid or not
            bool sf = true;
            int sz = x.size();
            if(n-ind <= sz){
                if(x[sz - (n-ind)] - '0' != i)sf = false;
            }
            // add the valid number of answers
            ans += rec(ind+1, tight&(i == hi), sf&isSuff, ss);
        }
        
        return dp[ind][tight][isSuff] = ans;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        x = s;
        lim = limit;
        string st = to_string(start-1), fin = to_string(finish);
        // calculate valid numbers from 1 to start-1 and 1 to finish, return the difference of them
        memset(dp, -1, sizeof dp);
        ll tot = rec(0, 1, 1, fin);
        memset(dp, -1, sizeof dp);
        ll pre = rec(0, 1, 1, st);
        return tot - pre;
    }
};
