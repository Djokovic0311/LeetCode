class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
	int n = size(triangle), level = 1;
	vector<vector<int> > dp(2, vector<int>(n, INT_MAX));
	dp[0][0]=triangle[0][0];  // assign top-most row to dp[0] as we will be starting from level 1
	for(; level < n; level++) 
		for(int i = 0; i <= level; i++)
			dp[level & 1][i] = triangle[level][i] + min(dp[(level - 1) & 1][min(i, n - 1)], dp[(level - 1) & 1][max(i - 1, 0)]); 
	level--; 
	return *min_element(begin(dp[level & 1]), end(dp[level & 1])); 
    }
};