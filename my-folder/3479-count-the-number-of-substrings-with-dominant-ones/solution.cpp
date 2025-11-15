class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> zero(n+1, 0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || (i > 0 && s[i - 1] == '0')) {
                zero[i + 1] = i;
            } else {
                zero[i + 1] = zero[i];
            }
        }

        for(int i = 1; i <= n; i++) {
            int cnt0 = s[i-1] == '0';
            int j = i;
            while(j > 0 && cnt0 * cnt0 <= n) {
                int cnt1 = (i - zero[j]) - cnt0;
                if(cnt0 * cnt0 <= cnt1) {
                    res += min(j - zero[j], cnt1 - cnt0 * cnt0+1);
                }
                j = zero[j];
                cnt0++;
            }
        }
        return res;

    }
};
