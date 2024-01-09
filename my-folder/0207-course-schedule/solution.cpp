class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        int count = 0;
        vector<int> indegree(numCourses, 0);
        
        vector<int> adj[numCourses];         // adj list        
        int edges = prerequisites.size();

        for(int i = 0;i<edges;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            count++;
            for(int i = 0; i < adj[node].size(); i++) {
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]] == 0)
                    q.push(adj[node][i]);
            }
        }
        return count == numCourses;        
    }
};
