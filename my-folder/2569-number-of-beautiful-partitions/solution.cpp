class Solution {
public:
int dp[1001][1001] = {};
bool isPrime(char ch) {
    return ch == '2' || ch == '3' || ch == '5' || ch == '7';
}
int dfs(int i, int k, int len, string &s) {
    if (k == 0)
        return i == s.size();
    if (i + len * k > s.size() || !isPrime(s[i]))
        return 0;
    if (dp[i][k] == 0) {
        dp[i][k] = 1;
        for (int j = i + len - 1; j < s.size(); ++j)
            if (!isPrime(s[j]))
                dp[i][k] = (dp[i][k] + dfs(j + 1, k - 1, len, s)) % 1000000007;
    }
    return dp[i][k] - 1;
}
int beautifulPartitions(string s, int k, int minLength) {
    return dfs(0, k, minLength, s);
}
};
