class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int res = 0;
        vector<int> record(n,0);
        int m = logs.size();
        for(int i = 0; i < m; i++) {
            if(i == 0) {
                record[logs[i][0]] = logs[i][1];
            }
            else {
                record[logs[i][0]] = max(record[logs[i][0]], logs[i][1]-logs[i-1][1]);
            }
        }
        return max_element(record.begin(), record.end()) - record.begin();
    }
};
