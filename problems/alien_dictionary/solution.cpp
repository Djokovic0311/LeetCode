class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res = "";
        queue<char> q;
        int n = words.size();
        if(n==0) return res;
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> graph;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < words[i].length(); j++) {
                indegree[words[i][j]] = 0;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            string cur = words[i];
            string nex = words[i + 1];
            if (cur.size() > nex.size() && cur.rfind(nex, 0) == 0) return "";
            int len = min(cur.size(), nex.size());
            for (int j = 0; j < len; j++) {
                if (cur[j] != nex[j]) {
                    unordered_set<char> set = graph[cur[j]];
                    if (set.find(nex[j]) == set.end()) {
                        graph[cur[j]].insert(nex[j]); // build graph
                        indegree[nex[j]]++; // add indegree
                    }
                    break;                        
                }
            }
        }        
        for (auto& e : indegree) {
            if (e.second == 0) {
                q.push(e.first);
            }
        }
        while(!q.empty()) {
            char c = q.front();
            q.pop();
            res += c;
            if (graph[c].size() != 0) {
                for(char ch : graph[c]) {
                    indegree[ch]--;
                    if(indegree[ch] == 0)
                        q.push(ch);
                }
            }
        }
        return res.length() == indegree.size() ? res : "";
    }
};