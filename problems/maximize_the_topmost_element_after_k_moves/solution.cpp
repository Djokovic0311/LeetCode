class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        priority_queue<int> pos;
        int n = nums.size();
        if(n==1 && k%2 == 1) return -1;
        // if(n==1 && k%2 == 0) return -1;
        // int res = -1;
        for(int i = 0; i <= min(n-1,k); i++) {
            if(i != k-1) pos.push(nums[i]);
        }
        return !pos.empty()? pos.top():-1;
    }
};