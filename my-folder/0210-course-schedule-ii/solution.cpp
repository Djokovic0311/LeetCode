class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> graph(numCourses);
        
        for(auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        vector<int> res;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
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
