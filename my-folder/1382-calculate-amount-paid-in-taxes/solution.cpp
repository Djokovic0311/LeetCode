class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int n = brackets.size();
        double res = 0;
        if(n==1) return double(min(income,brackets[0][0])) * brackets[0][1] / 100;
        res = double(min(income,brackets[0][0])) * brackets[0][1] / 100;
        for(int i = 1; i < n; i++) {
            if(brackets[i-1][0] >= income) return res;
            else {
                res += double(min(income,brackets[i][0])-brackets[i-1][0]) * brackets[i][1] / 100;
            }
        }
        return res;
    }
};
