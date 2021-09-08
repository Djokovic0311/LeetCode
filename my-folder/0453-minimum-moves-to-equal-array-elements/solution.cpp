class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum =0 , min_no =INT_MAX;
        for(int i:nums)
        {
            sum+=i;
            min_no = min(min_no, i);
        }
        return sum-nums.size()*min_no;
    }
};
