class Solution {
public:
    
    int getMaxDigit(int num) {
    int max_digit = -1;
    while (num) {
        max_digit = std::max(max_digit, num % 10);
        num /= 10;
    }
    return max_digit;
}



    int maxSum(vector<int>& nums) {
        unordered_map<int, std::vector<int>> max_digit_to_nums;

        for (int num : nums) {
            int max_digit = getMaxDigit(num);
            if (max_digit_to_nums[max_digit].size() < 2) {
                max_digit_to_nums[max_digit].push_back(num);
            } else {
                int minIndex = (max_digit_to_nums[max_digit][0] < max_digit_to_nums[max_digit][1]) ? 0 : 1;
                if (num > max_digit_to_nums[max_digit][minIndex]) {
                    max_digit_to_nums[max_digit][minIndex] = num;
                }
            }
        }

        int result = -1;
        for (auto& pair : max_digit_to_nums) {
            if (pair.second.size() == 2) {
                result = std::max(result, pair.second[0] + pair.second[1]);
            }
        }

        return result;        
    }
};
