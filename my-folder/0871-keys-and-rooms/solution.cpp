class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        int n = rooms.size();
        q.push(0);
        unordered_set<int> visited;
        while(!q.empty()) {
            int head = q.front();
            q.pop();
            int sz = q.size();
            visited.insert(head);
            for(int k : rooms[head]) {
                if (visited.find(k) == visited.end()) q.push(k);
            }
        }
        return visited.size() == rooms.size();
    }
};
