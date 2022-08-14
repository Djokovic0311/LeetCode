class Solution {
public:
    string smallestNumber(string pattern) {
	string ans = ":";
	int n = pattern.size();

	vector<char> tmp(n+1);
	iota(tmp.begin(), tmp.end(), '1');     // fills the vector with sequentially increasing values

	do {
		bool works = 1;

		for (int i = 1; i <= n; i++) {
			if (tmp[i] > tmp[i-1] && pattern[i-1] == 'D') {
				works = 0;
				break;
			}
			if (tmp[i] < tmp[i-1] && pattern[i-1] == 'I') {
				works = 0;
				break;
			}
		}

		if (works) {
			string x;
			for (int i = 0; i <= n; i++) {
				x += tmp[i];
			}
			ans = min(ans, x);
		}

	} while(next_permutation(tmp.begin(), tmp.end()));

	return ans;
}
};
