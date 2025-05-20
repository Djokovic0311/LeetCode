class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> difference(nums.size()+1, 0);
        for(const auto& query: queries) {
            int l = query[0], r = query[1];
            difference[l]++;
            difference[r+1]--;
        }
        vector<int> counts;
        int curr = 0;
        for(int d : difference) {
            curr += d;
            counts.push_back(curr);
        }
        for(int i = 0; i < nums.size(); i++) {
            if(counts[i] < nums[i])
                return false;
        }
        return true;
    }
};
