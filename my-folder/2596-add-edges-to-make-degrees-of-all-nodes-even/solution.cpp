class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        // vector<vector<bool>> adj(n+1,vector<bool>(n+1,false));
        vector<vector<int>> adj(n+1);
        int odd = 0;
        vector<int> odd_vertices;
        vector<int> degs(n+1,0);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degs[e[0]]++, degs[e[1]]++;
        }
        
        for(int i = 1; i <= n; i++) {
            if(degs[i] % 2 == 1) {
                odd++, odd_vertices.push_back(i);
            }
        }


//         for (int i = 1; i <= n; i++) {
//             int deg = 0;
//             for (int j = 1; j<= n; j++) {
//                 if (adj[i][j] == true) {
//                     deg++;
//                 }
//             }
//             if (deg % 2 == 1) {
//                 odd++;
//                 odd_vertices.push_back(i);
//             }
//         }
    // Given that we have at most 2 new edges to be added the number of odd nodes should not be more than 2
        if (odd == 0) {
            return true;
        } else if (odd == 2) {
            int a = odd_vertices[0];
            int b = odd_vertices[1];
            for (int k = 1; k <= n; k++) {
                if (find(adj[a].begin(),adj[a].end(),k) ==adj[a].end() && find(adj[b].begin(),adj[b].end(),k)==adj[b].end()){
                    return true;
                }
            }
            return false;
        } else if (odd == 4) {
            int a = odd_vertices[0];
            int b = odd_vertices[1];
            int c = odd_vertices[2];
            int d = odd_vertices[3];
            if ((find(adj[a].begin(),adj[a].end(),b)==adj[a].end() && find(adj[c].begin(),adj[c].end(),d)==adj[c].end()) ||
                (find(adj[a].begin(),adj[a].end(),c) ==adj[a].end()&& find(adj[b].begin(),adj[b].end(),d)==adj[b].end()) ||
                (find(adj[a].begin(),adj[a].end(),d) ==adj[a].end()&& find(adj[b].begin(),adj[b].end(),c)==adj[b].end())) {

               return true;
            }
            return false;
        } else {
            return false;
        }
        return false;
    }
};
