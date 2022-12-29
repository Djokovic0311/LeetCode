class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        using pp = pair<int,pair<int,int>>;
        vector<pp> v;
        int n = tasks.size();
        for(int i = 0; i < n; i++) {
            v.push_back({tasks[i][0],{tasks[i][1],i}});
        }
        sort(v.begin(), v.end());
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        long long curr = v[0].first;
        int i = 0;
        vector<int> res;
        while(i < n || !pq.empty()) {
            while(i < n && curr >= v[i].first) {
                pq.push({v[i].second.first,{v[i].second.second, v[i].first}});
                i++;
            }

            curr = curr + pq.top().first;
            res.push_back(pq.top().second.first);
            pq.pop();
            if(i < n && curr < v[i].first && pq.empty()){
                curr = v[i].first;
            }
        }
        return res;

    }
};
