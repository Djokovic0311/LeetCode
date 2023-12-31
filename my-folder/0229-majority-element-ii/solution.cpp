class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0, count2 = 0;
        int candidate1 = INT_MIN, candidate2 = INT_MIN;
        for(int num : nums) {
            if (candidate1 != INT_MIN && candidate1 == num) {
                count1++;
            } else if (candidate2 != INT_MIN && candidate2 == num) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1++;
            } else if (count2 == 0) {
                candidate2 = num;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        vector<int> result;
        for (int n: nums) {
            if (candidate1 != INT_MIN && n == candidate1) count1++;
            if (candidate2 != INT_MIN && n == candidate2) count2++;
        }

        if (count1 > n/3) result.push_back(candidate1);
        if (count2 > n/3) result.push_back(candidate2);
        return result;
    }
};
