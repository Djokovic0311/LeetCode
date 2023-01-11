class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, int> nodeParent;
        for (auto &e : edges){
            if (nodeParent.find(e[1]) == nodeParent.end()) nodeParent[e[1]] = e[0];
            else    nodeParent[e[0]] = e[1];
        }
        // for(auto it = nodeParent.begin(); it != nodeParent.end(); it++) {
        //     cout << it->first << ' ' << it->second << endl;
        // }
        queue<int> q;
        
        for (int i = 0; i < hasApple.size(); ++i)
            if (hasApple[i])  q.push(i);
        
        while (!q.empty()){
            int currIdx = q.front();
            q.pop();
            if (currIdx != 0){
                int nextIdx = nodeParent[currIdx];
				
                if (!hasApple[nextIdx]){
                    hasApple[nextIdx] = true;
                    q.push(nextIdx);
                }
            }
        }
        
        int countPath = accumulate(hasApple.begin(), hasApple.end(), -1);
        
        return countPath <= 0 ? 0 : 2 * countPath;
    }
};
