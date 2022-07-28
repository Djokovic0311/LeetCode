class Solution {
public:
    int dfs(vector<vector<int>>& stones, int index, vector<int>& visited, int n) {
        visited[index] = true;
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i] && (stones[index][0] == stones[i][0] || stones[index][1] == stones[i][1]))
               res += (dfs(stones,i,visited,n) + 1);
        }
        return res;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int res = 0;
        vector<int> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(vis[i]){continue;}
            res+=dfs(stones,i,vis,n);
        }
        return res;
    }
};