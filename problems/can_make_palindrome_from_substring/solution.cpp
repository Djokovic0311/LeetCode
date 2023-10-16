class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ret;
        vector<vector<int>> prefix;
        vector<int> temp(26, 0);
        prefix.push_back(temp);
        for(int i=0; i<s.length(); i++)
        {
            temp[s[i]-'a']++;
            prefix.push_back(temp);
        }
        for(int i=0; i<queries.size(); i++)
        {
            int hi = queries[i][1], lo = queries[i][0], k = queries[i][2];
            vector<int> sub = prefix[hi+1];
            int odd=0, sum=hi-lo+1;
            for(int j=0; j<26; j++)
            {
                sub[j] = sub[j] - prefix[lo][j];
                odd+=sub[j]%2;
            }
            bool t = (odd <= k*2 + sum%2);
            ret.push_back(t);
        }
        return ret;
    }
};