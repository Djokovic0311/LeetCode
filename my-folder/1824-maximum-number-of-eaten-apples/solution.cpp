class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size(), ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i=0; i<n || pq.size(); i++) {
            while(pq.size() && pq.top().first < i) pq.pop();

            if(i < n && apples[i]) pq.push({i + days[i] - 1, min(apples[i], days[i])});
            if(!pq.size()) continue;

            int d = pq.top().first, a = pq.top().second;
            pq.pop();
            if(a) a--, ans++;
        
            if(a && d > i) pq.push({d, a}); 
        }
        return ans;
        
    }
};
