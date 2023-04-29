class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        priority_queue<int> pq;
        for(int num : nums) {
            pq.push(num);
        }
        int res = 0;
        while(k) {
            int tmp = pq.top();
            res += tmp;
            pq.pop();
            pq.push(tmp+1);
            k--;
        }
        
        return res;
    }
};
