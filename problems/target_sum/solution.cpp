class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int,int>> mem(nums.size());
        return find(0,nums,S,mem);    
    }
    int find(int p, vector<int>& nums, int sum, vector<unordered_map<int,int>>& mem) {
        if(p==nums.size()) return sum==0;
        auto it = mem[p].find(sum);
        if(it != mem[p].end()) return it->second;
        return mem[p][sum]=find(p+1,nums,sum+nums[p],mem)+find(p+1,nums,sum-nums[p],mem);
    }
};