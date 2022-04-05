class Solution {
public:
    vector<string> turn(string s, int i) {
        vector<string> res(2, s);
        res[0][i] = '0' + (res[0][i] - '0' + 1) % 10;        // forward turn
        res[1][i] = '0' + (res[1][i] - '0' - 1 + 10) % 10;   // backward turn
        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(begin(deadends), end(deadends)), seen({"0000"});
        if(dead.find("0000")!=dead.end()) return -1;
        queue<string> q({"0000"});
        if(target == "0000") return 0;
        int n, minTurns = 0;
        while(!q.empty()) {            
            n = size(q), minTurns++;
            for(int i = 0; i < n; i++) { 
                auto cur_str = q.front(); q.pop();       
                for(int j = 0; j < 4; j++) 
                    for(auto adj_str : turn(cur_str, j)) 
                        if(seen.find(adj_str) == end(seen) && dead.find(adj_str) == end(dead)) 
                            if(adj_str == target) return minTurns;
                            else q.push(adj_str), seen.insert(adj_str);
            }
        }
        return -1;
    }
};
