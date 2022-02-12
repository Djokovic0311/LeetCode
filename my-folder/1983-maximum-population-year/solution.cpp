class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int pop[2051] = {}, res = 0;
        for (auto &l : logs) {
            ++pop[l[0]];
            --pop[l[1]];
        }
        for (auto i = 1950; i < 2050; ++i) {
            pop[i] += pop[i - 1];
            res = pop[i] > pop[res] ? i : res;
        }
        return res;        
    }
};
