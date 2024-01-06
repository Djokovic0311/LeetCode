class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int index = 1;
        while(index < n && nums[index] == nums[index-1]+1) {
            sum += nums[index++];
        }


        set<int> st(nums.begin(), nums.end());
        while(st.count(sum) != 0) {
            sum++;
        }
        return sum;
    }
};
