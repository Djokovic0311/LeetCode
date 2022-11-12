class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;
        for(int num : sticks) pq.push(num);
        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            x += pq.top();
            pq.pop();
            res += x;
            pq.push(x);
        }
        return res;        
    }
};