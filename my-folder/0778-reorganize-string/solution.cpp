#define p pair<char, int>

class Solution {
struct numcompare {
    bool operator() (const p &a, const p &b) {
        return a.second < b.second;
    }
};
public:
    string reorganizeString(string S) {
        unordered_map<char, int> map;
        priority_queue<p, vector<p>, numcompare> pq;
        for(char c : S) map[c]++;
        for(auto i : map) pq.push(i);
        string res = "";
        p prev{'#', -1};
        
        while(!pq.empty()) {
            p curr = pq.top();
            pq.pop();
            res += curr.first;
            if(prev.second > 0) pq.push(prev);
            map[curr.first]--;
            prev = {curr.first, map[curr.first]};
        }
        
        return res.size() == S.size() ? res : "";
    }
};
