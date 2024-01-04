class Solution {
public:
    void backtracking(vector<string>& mapping, vector<string>& res, string tmp, int index, string digits) {
        if(index == digits.length()) {
            res.push_back(tmp);
            return;
        }
        for(char c : mapping[digits[index]-'2']) {
            tmp += c;
            backtracking(mapping, res, tmp, index+1, digits);
            tmp.pop_back();
        }    
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> mappings{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;
        backtracking(mappings, ans, "", 0, digits);
        return ans;
    }
};
