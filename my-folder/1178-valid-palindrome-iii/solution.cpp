class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.length();
        vector<int> dp1(n,0), dp2(n);
        for(int i = 0; i <n-1; i++) {
            if(s[i] == s[i+1]) {
                dp2[i] = 0;
            }
            else dp2[i] = 1;
        }
        for(int l = 3; l <= n; l++) {
            vector<int> tdp(n-l+1);
            for(int i = 0; i < n-l+1;i++) {
                int j = i+l-1;
                if(s[i] == s[j]) {
                    tdp[i] = dp1[i+1];
                } else {
                    tdp[i] = 1 + min(dp2[i], dp2[i+1]);
                }
            }
            dp1 = dp2;
            dp2 = tdp;
        }

        return dp2[0] <=k;
    }
};
