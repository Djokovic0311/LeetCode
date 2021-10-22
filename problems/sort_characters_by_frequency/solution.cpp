namespace
{
	typedef std::pair<char, int> PAIR;
	bool fun_cmp_by_value(const PAIR& left, const PAIR& right) {
		return left.second > right.second;
	}
 
	struct funCmpByValue {
		bool operator()(const PAIR& left, const PAIR& right) {
			return left.second > right.second;
		}
	};
}

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        string res;
	    std::vector<PAIR> a(mp.begin(), mp.end());
	    sort(a.begin(), a.end(), funCmpByValue());
        for(auto pair: a) {
            for(int j = 0; j < pair.second; j++) {
                res += pair.first;
            }
        }   
        return res;
    }
};