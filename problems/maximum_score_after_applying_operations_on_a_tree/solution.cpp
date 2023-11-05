class Solution {
public:
    vector<vector<int>> adj;
    long long solve(int node,int parent,vector<int>& values){
        if(adj[node].size()==1 && node!=0)
            return values[node];
        long long sum = 0;
        for(auto it : adj[node]){
            if(it==parent)
                continue;
            sum += solve(it,node,values);
        }
        return min(sum,1LL*values[node]);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        adj.resize(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        long long ans = 0;
        for(int i=0;i<n;i++)
            ans += values[i];
        long long x = solve(0,-1,values);
        
        return ans-x;
    }
};