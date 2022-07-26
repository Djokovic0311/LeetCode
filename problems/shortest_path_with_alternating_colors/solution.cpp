class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n);
        vector<vector<int>> r(n), b(n);
        for(auto red : redEdges) {
            r[red[0]].push_back(red[1]);
            
        }
        for(auto blue : blueEdges) {
            b[blue[0]].push_back(blue[1]);
        }
        queue<pair<int,int>> q;
        q.push({0,1});
        q.push({0,-1});
        vector<pair<int,int>> record(n,{INT_MAX,INT_MAX});
        record[0] = {0,0};
        int currDist=0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0;i < sz; i++) {
                auto [node, edge] = q.front();
                q.pop();
                if(edge == 1) {
                    for(auto x : r[node]) {
                        if(record[x].second > currDist +1) {
                            q.push({x,-1});
                            record[x].second = currDist + 1;
                        }
                    }
                }
                else {
                    for(auto y : b[node]) {
                        if(record[y].first > currDist +1) {
                            q.push({y,1});
                            record[y].first = currDist + 1;
                        }
                    }
                }
            }
            currDist++;
        }
        for(int i=0;i<n;i++)
        {
            int mini=min(record[i].first,record[i].second);
            res[i]=(mini==INT_MAX) ? -1 : mini;
        }
        return res;        
    }
};