class Solution {
public:
    queue<int> q;
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<bool> visited(friends.size(),false);     
        unordered_map<string,int> count;      
        vector<pair<int,string>> resultPairs;
        vector<string> result;
        q.push(id);                  
        visited[id]=true;            
        while(!q.empty()&&level--)	{		
            for(int i=q.size();i;q.pop(),i--) {
                for(int &i:friends[q.front()])
                    if(!visited[i]) {
                        visited[i]=true;
                        q.push(i);
                    }
            }
        }
        while(!q.empty()) {                    
            for(string &s:watchedVideos[q.front()])
                count[s]++;
            q.pop();
        }
        for(auto it=count.begin();it!=count.end();it++)
            resultPairs.push_back({it->second,it->first});
        sort(resultPairs.begin(),resultPairs.end());
        transform(resultPairs.begin(),resultPairs.end(),back_inserter(result),[](pair<int,string>&p){return p.second;}); //Transform the pairs to result
        return result;                 
    }
};
