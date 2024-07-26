class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int,int>>>adj;

        for(auto edge: edges){

            adj[edge[0]].push_back(make_pair(edge[1],edge[2]));
            adj[edge[1]].push_back(make_pair(edge[0],edge[2]));
        }

       int city=-1;
       int prev=n;

        for(int i=0; i<n; i++){
            set<pair<int,int>>st;
            vector<int>distance(n,1e5);

            st.insert(make_pair(0,i));
            distance[i]=0;

            while(!st.empty()){
                auto top = *(st.begin());
                st.erase(st.begin());

                int cost = top.first;
                int node =top.second;

                for(auto neigbhours : adj[node]){
                    if(cost + neigbhours.second < distance[neigbhours.first]){
                        auto record = st.find(make_pair(distance[neigbhours.first],neigbhours.first));

                        if(record!=st.end()){
                            st.erase(record);
                        }
                        distance[neigbhours.first]= cost + neigbhours.second;
                        st.insert({distance[neigbhours.first], neigbhours.first});
                    }
                }
            }

            int ct=0;
            for(auto a: distance){
                if(a<=distanceThreshold){
                    ct++;
                }
            }
            if(ct<=prev){
                prev=ct;
                city= max(i,city);
            }
        }

        return city;

    }
};
