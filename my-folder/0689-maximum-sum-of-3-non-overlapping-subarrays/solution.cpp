class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        vector<int> subArr(n-k+1);
        for(int i= 0; i <= n-k; i++) {
            subArr[i] = prefix[i+k-1] - (i>0?prefix[i-1]:0);
        }
        
        int dp[4][n][4];
        memset(dp, 0, sizeof (dp));
        for(int i = 1; i < 4; i++) {
            for(int j = 0; j <= n-k; j++) {
                int a = j > 0 ? dp[i][j-1][0] : 0;
                int b = subArr[j] + (j-k>=0 ? dp[i-1][j-k][0]: 0);
                if(a >= b) {
                    dp[i][j][0] = a;
                    for(int p = 1; p <= i; p++) {
                        dp[i][j][p] = j > 0 ? dp[i][j-1][p] : -1;
                    }
                } else {
                    dp[i][j][0] = b;
                    for(int p = 1; p <= i-1; p++) {
                        dp[i][j][p] = j-k>=0 ? dp[i-1][j-k][p] : -1;
                    }
                    dp[i][j][i] = j;
                }

            }
        }

        vector<int> res(3, 0);
        for(int i=1; i<=3; i++) {
            res[i-1] = dp[3][n-k][i];
        }

        return res;
    }
};
