class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto e : flights) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        int ans=INT_MAX;
        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops=0;
        while(stops<=k && !q.empty()) {
            int sz=q.size();
            while(sz--) {
                int cnode=q.front().first;
                int cdist=q.front().second;
                q.pop();
                if(cdist>dist[cnode]) continue;
                dist[cnode]=cdist;
                for(auto e : graph[cnode]) {
                    if(e.second+cdist>ans) continue;
                    if(e.first==dst) ans=min(ans, e.second+cdist);
                    q.push({e.first, e.second+cdist});
                }
            }
            stops++;
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};