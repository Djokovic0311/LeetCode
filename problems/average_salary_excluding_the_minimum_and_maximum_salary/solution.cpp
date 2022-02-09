class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        int n = salary.size();
        double res = 0;
        for(int i = 1; i < n-1; i++) {
            res += salary[i];
        }
        res /= (n-2);
        return res;
    }
};