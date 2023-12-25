class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        unordered_map<char,unordered_set<char>> adjList;
        unordered_map<char,int> indegree;
        queue<char> q;
        string res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < words[i].length(); j++) {
                indegree[words[i][j]] = 0;
            }
        }

        for(int i = 0; i < n-1; i++) {
            string curr = words[i], nxt = words[i+1];
            if(curr.length() > nxt.length() && curr.substr(0, nxt.length()) == nxt) {
                return "";            
            }
            int len = min(curr.length(), nxt.length());
            for(int j = 0; j < len; j++) {
                if(curr[j] != nxt[j]) {
                    unordered_set<char> set = adjList[curr[j]];
                    if (set.find(nxt[j]) == set.end()) {
                        adjList[curr[j]].insert(nxt[j]); 
                        indegree[nxt[j]]++; 
                    }
                    break;    
                }
            }
        }

        for(auto it : indegree) {
            if(it.second == 0) {
                q.push(it.first);
                
            }
        }

        while(!q.empty()) {
            auto c = q.front();
            q.pop();
            res += c;
            if(adjList[c].size() > 0) {
                for(auto neighbor : adjList[c]) {
                    indegree[neighbor]--;
                    if(indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
        }
        return res.length() == indegree.size() ? res : "";
    }
};
