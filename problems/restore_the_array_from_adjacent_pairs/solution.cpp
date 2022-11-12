class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> res;
        unordered_map<int,bool>visited;
        unordered_map<int,vector<int>>mp;
        int n = adjacentPairs.size();
        for(auto p : adjacentPairs) {
            mp[p[0]].push_back(p[1]);
            mp[p[1]].push_back(p[0]);
        }
        int start;
        for(auto x:mp){
           if(x.second.size()==1){
               start=x.first;
               break;
           }
        }

        while(!visited[start]) {
            res.push_back(start);
            visited[start]=true;
            for(auto e : mp[start]) {
                if(!visited[e]) {
                    start = e;
                    break;
                }
            }
        }

        return res;
    }
};