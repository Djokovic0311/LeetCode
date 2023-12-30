class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for(char c : s) {
            mp[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }

        string res;
        while(!pq.empty()){
            auto tmp = pq.top();
            pq.pop();
            res += string(tmp.first, tmp.second) ;
        }

        return res;
    }
};
