class Router {
    queue<vector<int>> q;
    set<vector<int>> exists;
    int size;
    map<int, pair<int, vector<int>>> mp;
    // des, {count, timestamp}
public:
    Router(int memoryLimit) {
        size = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};
        if(exists.find(packet) != exists.end()) {
            return false;
        } else {
            if(q.size() == size) {
                vector<int> tmp = q.front();
                q.pop();
                exists.erase(tmp);
                mp[tmp[1]].first++;
            }
            q.push(packet);
            exists.insert(packet);
            if(mp.find(destination) == mp.end()) {
                mp[destination].first = 0;
            } 
            mp[destination].second.push_back(timestamp);
            return true;
        }
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) {
            return {};
        } else {
            vector<int> packet = q.front();
            q.pop();
            exists.erase(packet);
            mp[packet[1]].first++;
            return packet;
        }
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int s = mp[destination].first;
        vector<int>& v = mp[destination].second;

        int start = lower_bound(v.begin(), v.end(), startTime) - v.begin();
        int end = upper_bound(v.begin(), v.end(), endTime) - v.begin();
        
        int res = end-start;
        if(start < s) {
            res -= (s-start);
        }
        res = max(res, 0);
        return res;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
