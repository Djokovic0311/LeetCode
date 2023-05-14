class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> score(1 << n, 0);
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                score[(1 << i) | (1 << j)] = __gcd(nums[i], nums[j]);
            }
        }
        vector<int> dp(1 << n, 0);
        for (int i = 1; i <= n / 2; i++){
            for (int w = (1 << (2 * i)) - 1; w < (1 << n); w = nextPerm(w)){
                for (int s = w; s; s = (s - 1) & w) if (__builtin_popcount(s) == 2){
                    dp[w] = max(dp[w], dp[w - s] + i * score[s]);
                }
            }
        }
        return dp[(1 << n) - 1];
        
    }
    
    inline int nextPerm(int v) {
        int t = v | (v - 1);
        return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
    }
};