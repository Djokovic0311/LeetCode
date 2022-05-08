class Solution {
public:
    string largestGoodInteger(string num) {
        int tmp = INT_MIN;
        int n = num.length();
        string res;
        for(int i = 0; i < n-2; i++) {
            if(num[i] == num[i+1] && num[i] == num[i+2] && stoi(num.substr(i,1)) > tmp) {
                tmp = stoi(num.substr(i,1));
                res = num.substr(i,3);
            }
        }
        return res;
    }
};