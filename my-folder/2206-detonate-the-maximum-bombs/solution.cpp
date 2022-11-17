class Solution {
public:
    void dfs(int node, vector<bool>&visited, vector<int>adj[], int &currDiffused){
        
        currDiffused += 1;// increasing the number of bombs getting detonated as we do dfs traversal
        
        for(auto child : adj[node]){
            if(!visited[child]){
                visited[child] = true;
                dfs(child, visited, adj, currDiffused);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& arr) {
        
        int n = arr.size();
        vector<int>adj[n];
        
        //forming adjacency list
        for(int i = 0; i < n; i++){
            
            long long x = arr[i][0], y = arr[i][1], r = arr[i][2];
            for(int j = 0; j < n; j++){
                
                if(i == j) continue;// current cirle(node) can't have itself as its adjacent node
                
                long long xx = arr[j][0], yy = arr[j][1];
                long long diffx = (x - xx) * (x - xx), diffy = (y - yy) * (y - yy), rSquare = r * r;
                if(diffx + diffy <= rSquare){// jth bomb will also diffuse if it's center lies inside the ith bomb's range, so jth bomb will be adjacent node to ith bomb
                    adj[i].push_back(j);
                }
                
            }
        }
        
        int maxDiffused = 0;//will store maximum bombs that can be detonated
        for(int node = 0; node < n; node++){
            
            vector<bool>visited(n, false);
            
            int currDiffused = 0;// It stores maximum bombs that will be detonated, if we detonate current bomb node
            if(!visited[node]){
                
                visited[node] = true;
                dfs(node, visited, adj, currDiffused);
            }
          
            maxDiffused = max(maxDiffused, currDiffused);
        }
        
        return maxDiffused;
    }
};
