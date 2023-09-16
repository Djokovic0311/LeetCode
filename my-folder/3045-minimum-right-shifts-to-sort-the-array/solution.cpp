class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    
    if(nums == sorted) return 0;
    
    int n = nums.size();
    for(int i = 1; i < n; ++i) {
        rotate(nums.begin(), nums.end() - 1, nums.end());
        if(nums == sorted) return i;
    }
    return -1;    
    }
};
