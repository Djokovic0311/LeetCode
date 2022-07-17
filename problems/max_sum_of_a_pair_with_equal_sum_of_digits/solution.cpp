class Solution {
public:
    int countDigitSum(int n) {
        int res = 0;
        while(n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    int maximumSum(vector<int>& nums) {
        map<int,priority_queue<int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[countDigitSum(nums[i])].push(nums[i]);
        }
        int res = -1;
        bool valid = false;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            auto pq = it->second;
            int tmp = 0;
            if(pq.size()>=2) {
                valid = true;
                tmp += pq.top();
                pq.pop();
                tmp += pq.top();
                pq.pop();
            }
            res = max(res, tmp);
        }
        return valid == true? res : -1;
    }
};