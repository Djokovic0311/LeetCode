class Solution {
public:
    bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> record(n+1);
        for(int i = 0; i < k; i++) {
            int start = queries[i][0], end = queries[i][1], val = queries[i][2];
            record[start] += val;
            record[end+1] -= val;
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += record[i];
            if(nums[i] > sum) return false;
        }

        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int k = 0;
        int n = nums.size();
        int l = 0, r = queries.size();
        if(!canFormZeroArray(nums, queries, r)) return -1;
        while(l <= r) {
            int mid = l + (r-l) / 2;
            if(canFormZeroArray(nums, queries, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
