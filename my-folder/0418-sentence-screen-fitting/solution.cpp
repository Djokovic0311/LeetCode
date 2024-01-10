class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        vector<int> dp(n, 0);
        int res= 0;
        for(int i = 0; i < n; i++) {
            int len = 0;
            int cnt = 0;
            int start = i;
            while(len <= cols) {
                len += sentence[start].size();
                start = (start + 1) % n;
                cnt++;
                if(len < cols)
                    len++;
            }
            dp[i] = cnt-1;
        }
        for(int i = 0, k = 0; i < rows; i++) {
            res += dp[k];
            k = (k + dp[k]) % n;
        }
        return res / n;

    }
};
