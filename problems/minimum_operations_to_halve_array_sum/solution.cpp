class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        priority_queue<double> q;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            q.push(nums[i]);
        }
        double half = double(sum) / 2;
        double reduced = 0;
        while(reduced < half) {
            double tmp = q.top();
            reduced += tmp / 2;
            q.pop();
            q.push(tmp / 2);
            cnt++;
        }
        return cnt;
    }
};