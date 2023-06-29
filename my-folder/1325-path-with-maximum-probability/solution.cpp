class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //create adjacency list
        vector<pair<int, double>> adj[n];
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        //create the distance/probability array 
        vector<double> prob(n , 0);

        priority_queue<pair<double , int>> pq;
        pq.push(make_pair(1,start));

        while(!pq.empty()){
            auto front = pq.top();
            double nodeProb = front.first;
            int node = front.second;
            pq.pop();

            if(node == end)
                return nodeProb;

            for(auto i : adj[node]){
                if(nodeProb * i.second > prob[i.first]){
                    prob[i.first] = nodeProb * i.second;
                    pq.push(make_pair(prob[i.first] , i.first));
                }
            }
        }
        
        return 0;
    }
};
