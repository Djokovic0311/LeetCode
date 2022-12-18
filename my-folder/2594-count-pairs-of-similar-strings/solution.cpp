class Solution {
public:
    
string duplicate(string str)
{
	if(str.size()<2)
		return str;
	string tmp_str("\0");
	tmp_str+=str[0];
	string::size_type j;
	for(string::size_type i=1 ; i<str.size() ; i++)
	{
		for(j=0 ; j<tmp_str.size() ; j++)
		{
			if(tmp_str[j]==str[i])
				break;
		}
		if(j==tmp_str.size())
			tmp_str+=str[i];
	}
	return tmp_str;
}

    int similarPairs(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i < n; i++) {
            string res = duplicate(words[i]);
            sort(res.begin(), res.end());
            words[i] = res;
        }
        
        unordered_map<string, int> mp;
        for(string w : words) {
            mp[w]++;
        }
        int res = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {

                res += it->second * (it->second-1) /2;
        }
        
        return res;
    }
};
