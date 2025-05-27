class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // int res = 0;
        int n = colors.length();

        vector<vector<int>> adjList(n), cnt(n, vector<int>(26));
        vector<int> indegree(n);

        for(auto & e : edges) {
            adjList[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        vector<int> q;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) {
                q.push_back(i);
            }
        }
        int res = 0, processed = 0;

        while(!q.empty()) {
            vector<int> q1;
            for (auto i : q) {
                ++processed;
                res = max(res, ++cnt[i][colors[i] - 'a']);
                for (auto j : adjList[i]) {
                    for (auto k = 0; k < 26; ++k)
                        cnt[j][k] = max(cnt[j][k], cnt[i][k]);
                    if (--indegree[j] == 0)
                        q1.push_back(j);
                }
            }
            swap(q, q1);

        }
        return processed != n ? -1 : res;
    }
};
