class Solution {
public:
    int caculate(string s) {
        int index = s.find('+');
        int left, right;
        if(index == 0) left = 0;
        else left = stoi(s.substr(0,index));
        if(index == s.length()-1) right = 0;
        else right = stoi(s.substr(index+1));
        return left+right;
    }
    string minimizeResult(string expression) {
        int n = expression.length();
        vector<vector<int>> dp(n, vector<int>(n,0));
        int index = expression.find('+');
        int res = INT_MAX;
        vector<int> record(2,0);
        record[1] = n-1;
        for(int i = 0; i < index;i++) {
            for(int j = index+1; j <= n; j++) {
                int mul;
                if(i == 0) mul = 1;
                else mul = stoi(expression.substr(0,i));
                if(j < n-1) mul *= stoi(expression.substr(j+1));
                
                int tmp = mul * caculate(expression.substr(i,j-i+1));
                if(tmp<res) {
                    res = tmp;
                    record[0] = i;
                    record[1] = j;
                }
            }
        }
        string s = "";
        cout << record[0] << ' ' << record[1];
        for(int i = 0; i < n; i++) {
            if(i == record[0]) s += '(';
            
            s += expression[i];
            if(i == record[1]) s += ')';
        }
        return s;
    }
};
