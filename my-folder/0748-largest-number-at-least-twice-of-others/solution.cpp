class Solution {
public:
    int dominantIndex(vector<int>& nums) {

        int pos = 0;
        int n = nums.size();
        if(n==1) return 0;
        int first = max(nums[0],nums[1]);
        int second = min(nums[1],nums[0]);
        pos = nums[0]>nums[1]?0:1;
        if(n == 2 && first >= second * 2) return nums[0]>nums[1]?0:1;
        else if (n==2) return -1;
        for(int i = 2; i < n; i++) {
            if(nums[i] > first) {
                second = first;
                first = nums[i];
                pos = i;
            }
            else if(nums[i] > second) {
                second = nums[i];
            }
        }
        if(first >= second * 2) return pos;
        else return -1;
    }
};
