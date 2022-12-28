class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq;
        for(int p : piles) pq.push(p);

        while(k > 0) {
            k--;
            int tmp = pq.top();
            pq.pop();
            pq.push(tmp-floor(double(tmp)/2));
        }

        int res = 0;
        while(!pq.empty()) {
            res += pq.top();
            pq.pop();

        }
        return res;
    }
};
