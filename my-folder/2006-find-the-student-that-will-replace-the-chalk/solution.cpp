class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        int i = 0;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += chalk[i];
        }
        k %= sum;
        while(k >= chalk[i]) {
            k -= chalk[i++];
            i %= n;
        }
        return i;
    }
};
