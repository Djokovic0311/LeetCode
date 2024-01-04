class Solution {
public:
    vector<string> expressions;
    vector<string> addOperators(string num, int target) {
        dfs(num , target , 0 , "" , 0 , 0);
        return expressions;
    }
    void dfs(string &num , int target , int index , string path , long int res , long int prev)
    {
        if(index == num.length() && res == target) {
            expressions.push_back(path);
            return;
        }
        
        for(int i = index; i < num.length(); i++) {
            string s = num.substr(index, i-index+1);
            if(s.length() > 1 && s[0] == '0') break;
            long int curr = stol(s);
            if(index == 0) {
                dfs(num, target, i+1, s, curr, curr);
            } else {
                dfs(num, target, i+1, path+"+"+s, res + curr, curr);
                dfs(num, target, i+1, path+"-"+s, res - curr, -curr);
                dfs(num, target, i+1, path+"*"+s, res - prev + curr * prev, prev * curr);
            }
        }
    }
    
};
