class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        unordered_map<int,vector<int>> adjList;
        vector<int> indegrees(n+1,0);
        for(auto r : relations) {
            indegrees[r[1]]++;
            adjList[r[0]].push_back(r[1]);
        }
        int res = 0;
        queue<int> q;
        for(int i = 1; i < n+1; i++) {
            if(indegrees[i] == 0) {
                q.push(i);
            }
        }
        int studied = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                studied++;
                for(auto adj: adjList[node]) {
                    indegrees[adj]--;
                    if(indegrees[adj] == 0) {
                        q.push(adj);
                    }
                }

            }
            res++;
        }
        
        return studied == n ? res : -1;
    }
};
