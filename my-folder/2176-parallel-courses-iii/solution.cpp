class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1, 0);
        for (const auto& relation : relations) {
            graph[relation[0]].push_back(relation[1]);
            indegree[relation[1]]++;
        }
        
        // BFS to calculate the time needed to finish each course including its prerequisites
        vector<int> totalTime(n + 1);
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                totalTime[i] = time[i - 1];
            }
        }
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : graph[cur]) {
                totalTime[next] = max(totalTime[next], totalTime[cur] + time[next - 1]);
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        // The result is the maximum time among all courses
        int res = *max_element(totalTime.begin(), totalTime.end());
        return res;
    }
};

