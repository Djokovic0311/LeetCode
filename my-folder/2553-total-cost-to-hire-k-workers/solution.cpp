class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long total = 0;
        int n = costs.size();
        priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        int i, j;
        for(i = 0, j = n-1; i < candidates && i <= j; i++, j--) {
            if(i!=j)
                pq.push(make_pair(costs[i],i)), pq.push(make_pair(costs[j],j));
            else pq.push(make_pair(costs[i],i));
        }
        // cout << pq.size() << endl;
        // cout << i << '  ' << j <<endl;
        
        while(k) {
            auto [c, idx] = pq.top();
            pq.pop();
            total += c;
            // cout << c << ' ' << idx << endl;
            // cout << candidates << ' ' << n << endl;
            if(2 * candidates < n) {
                // cout << "here" <<endl;
                if(idx < i) {
                    pq.push(make_pair(costs[i],i));
                    i++;
                }
                else {
                    pq.push(make_pair(costs[j],j));
                    j--;
                }
                n--;
            }
            k--;
        }
        return total;
    }
};
