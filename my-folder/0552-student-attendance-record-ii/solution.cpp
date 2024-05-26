class Solution {
public:
    const long long mod=1e9+7;
    int checkRecord(int n) {
        int dp[2][2][3]={0};// C-array is fast, optimized space
        fill(&dp[0][0][0], &dp[0][0][0]+6, 1);// dp[0][j][k]=1 for all j, k
        for(int i=1; i<=n; i++){
            for(int j=0; j<=1; j++){//absent
                for(int k=0; k<=2; k++){//late
                    long long ans=dp[(i-1)&1][j][0];//P
                    ans+=(k<2?dp[(i-1)&1][j][k+1]:0);// L
                    ans+=(j==0?dp[(i-1)&1][j+1][0]:0);// A
                    dp[i&1][j][k]=ans%mod;
                }
            }
        }
        
        return dp[n&1][0][0];
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
