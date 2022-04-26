class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0;
        int win = 0, maxwin = 0;
        for(int i = 0; i < n; i++) {
            sum += (!grumpy[i]) * customers[i];
            win +=customers[i]*grumpy[i];
            if(i >= minutes) win -= customers[i-minutes] * grumpy[i-minutes];
            maxwin = max(maxwin, win);
        }
        return sum + maxwin;
    }
};