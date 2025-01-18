class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
     sort(nums.begin(), nums.end());
    int mini = nums[0];
    int sum = 0;
    while(mini) {
        sum += mini % 10;
        mini /= 10;
    }
    return (sum+1) % 2;
    }
};
