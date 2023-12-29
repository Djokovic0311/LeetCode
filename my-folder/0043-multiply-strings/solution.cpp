class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        if (num1 == "0" || num2 == "0") return "0";
        vector<int> res(m+n, 0);
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                res[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
                res[i+j] += res[i+j+1] / 10;
                res[i+j+1] %= 10;
            }
        }
        int index = 0;
        string s= "";
        while(res[index] == 0) index++;
        while(index < res.size()) {
            s += res[index++] + '0';
        }
        return s;
    }
};
