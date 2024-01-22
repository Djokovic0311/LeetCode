class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        vector<vector<int>> adjList(n);
        vector<int> indegree(n);
        for(auto e : edges) {
            indegree[e[1]]++;
            adjList[e[0]].push_back(e[1]);
        }
        queue<int> q;
        vector<set<int>>temp(n);
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            } 
        }
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            for(auto neighbor : adjList[curr]) {
                for(auto r : temp[curr]) {
                    temp[neighbor].insert(r);
                }
                temp[neighbor].insert(curr);
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        for(int i=0;i<n;++i)
        { 
            res[i]=vector<int>(temp[i].begin(),temp[i].end()); 
        }

        return res;
    }
};
