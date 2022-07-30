class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        queue<int> q;
        vector<bool> res;
        vector<vector<int>> isReachable(numCourses, vector<int> (numCourses, 0));
        vector<vector<int>> adj(numCourses);
        vector<vector<int>> visited(numCourses, vector<int>(numCourses, 0));
        for(auto& v : prerequisites) {
            adj[v[0]].push_back(v[1]);
        }
        for(int i = 0; i < numCourses; i++) {
            q.push(i);
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for(int neighbor : adj[node]) {
                    if(visited[i][neighbor]) continue;       
                    isReachable[i][neighbor]  = 1;
                    visited[i][neighbor] = 1;          
                    q.push(neighbor);                    
                }
            }
        }
        for(auto& q : queries) {
            res.push_back(isReachable[q[0]][q[1]]);
        }
        return res;
    }
};
