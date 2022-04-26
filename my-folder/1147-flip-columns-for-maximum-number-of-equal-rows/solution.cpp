class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& M) {
		unordered_map<string, int> map;

		for (auto& r : M) {
			// generate the pattern for the current row
			string s(r.size(), 'T');
			for (int i = 1; i < r.size(); i++) {
				if (r[i] != r[0]) s[i] = 'F';
			}
			// put the pattern to map
			map[s]++;
		}

		// find the highest freq of the pattern
		int ans = 0;
		for (auto& p : map)
			ans = max(ans, p.second);
		
		return ans;        
    }
};
