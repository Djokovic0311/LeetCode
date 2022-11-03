class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        for(auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> res;
        while(!q.empty()) {
            int tmp = q.front();
            res.push_back(tmp);
            q.pop();
            for(int i = 0; i < graph[tmp].size(); i++) {
                int curr = graph[tmp][i];
                indegree[curr]--;
                if(indegree[curr]==0)
                    q.push(curr);
            }
            
        }
        if (res.size() != numCourses)
        res.clear();
        return res;
    }
};
