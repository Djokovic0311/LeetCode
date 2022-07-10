class Solution {
public:
    int fillCups(vector<int>& amount) {
        int res = 0;
        priority_queue<int> pq;
        for(auto a : amount) pq.push(a);
        while(pq.top() > 0) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(b == 0) {
                res += a;
                break;
            }
            else {
                res++;
                pq.push(a-1);
                pq.push(b-1);
            }
        }
        return res;
    }
};