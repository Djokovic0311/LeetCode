class Solution {
public:
    double calculateRatioGain(int pass, int total) {
        return (double)(pass+1) / (double)(total+1) - (double)pass / (double)total;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double res = 0;
        priority_queue<pair<double, pair<int, int>>> pq;
        for(auto cls: classes) {
            pq.push(make_pair(calculateRatioGain(cls[0], cls[1]), make_pair(cls[0], cls[1])));
        }

        while(extraStudents--) {
            auto [currentGain, cls] = pq.top();
            pq.pop();
            int pass = cls.first, total = cls.second;
            pq.push({calculateRatioGain(pass+1, total+1), {pass+1, total+1}});
        }

        while(!pq.empty()) {
            auto [_, cls] = pq.top();
            pq.pop();
            res += (double) cls.first / (double) cls.second;
        }

        return res / classes.size();
    }
};
