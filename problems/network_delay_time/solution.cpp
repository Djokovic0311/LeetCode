class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++)
                adj[times[i][0]].push_back({times[i][1],times[i][2]});
        vector<int> dist(n+1,INT_MAX);
        queue<int> q;
        q.push(k);
        dist[k]=0;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(pair<int,int> it:adj[t])
            {
                if(dist[it.first]>dist[t]+it.second)
                {
                    dist[it.first]=dist[t]+it.second;
                    q.push(it.first);
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            res=max(res,dist[i]);
        }
        return res;
    }
};