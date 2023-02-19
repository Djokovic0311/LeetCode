#define ll long long
ll dp[1111][1 << 11];
ll mod;
class Solution {
public:
    vector<int> primes;
    ll getMask(ll num) {
        ll mask = 0;
        for(int i = 0; i < 10; i++) {
            int tim = 0;
            while(num % primes[i] == 0) {
                tim += 1;
                num /= primes[i];
            }
            if(tim > 1) return -1;// if a number is getting divided with a prime more than 1 time meaning it can be divided by that primes square
            if(tim == 1) mask |= (1 << (i + 1)); // i + 1 because the for i == 0 product 1 has already been taken
        }
        return mask;
    }
    ll dfs(int ind, ll prodmask, vector<int> &nums) {
        if(ind >= nums.size()) return 1;
        if(dp[ind][prodmask] != -1) return dp[ind][prodmask];
        
        ll mask = getMask(nums[ind]);
        ll ans = dfs(ind + 1, prodmask, nums);
        
        if((prodmask & mask) == 0) {
            ans = (ans + dfs(ind + 1, prodmask | mask, nums)) % mod;
        }
        return dp[ind][prodmask] = ans;
    }
    int squareFreeSubsets(vector<int>& nums) {
        mod = 1e9 + 7;
        memset(dp, -1, sizeof dp);
        primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        return dfs(0, 1, nums) - 1; // -1 because of the case when we have not taken any number
    }
};
