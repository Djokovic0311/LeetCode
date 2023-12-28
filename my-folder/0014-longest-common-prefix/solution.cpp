class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs[0].length();
        int i = 0;
        while(i < n &&strs[0][i] == strs[strs.size()-1][i]) i++;
        return strs[0].substr(0,i);
    }
};
