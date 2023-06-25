class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        int n = nums.size();
        vector<int> record;
        long long res = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                record.push_back(i);
            }
        }
        if(record.size() == 0) return 0;
        for(int i=0; i < record.size()-1; i++) {
            long long tmp = record[i+1] - record[i];
            // cout << tmp;
            res = (res * tmp) % MOD;
            
        }
        
        return (int) res;
    }
};

