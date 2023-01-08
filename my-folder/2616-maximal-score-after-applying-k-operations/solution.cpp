class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0;
        
        priority_queue<int> pq;
        for(int num : nums) pq.push(num);
        while(k) {
            k--;
            int top = pq.top();
            pq.pop();
            pq.push(ceil(double(top)/3));
            res += top;
        }
        return res;
        
    }
};
