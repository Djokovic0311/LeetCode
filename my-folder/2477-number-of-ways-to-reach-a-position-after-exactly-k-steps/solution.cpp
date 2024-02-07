class Solution {
public:
    int mod = 1e9+7;
    int recursive(int s, int e, int k, unordered_map<int, unordered_map<int,int>>&mp){
        if(s == e && k==0)
            return 1;

        if(k == 0) 
            return 0;

        if(mp[s].count(k))
            return mp[s][k];

        return mp[s][k] = ((recursive(s+1, e, k-1, mp)%mod) + (recursive(s-1, e, k-1, mp)%mod)) %mod;
    }

    int numberOfWays(int startpos, int endpos, int k) {
        unordered_map<int, unordered_map<int,int>>mp;
        return recursive(startpos, endpos, k, mp);
    }
};
