class Solution {
public:
    
    bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
        i += 6;
    }
    return true;
}
    
    std::vector<int> extract_diagonals(const std::vector<std::vector<int>>& nums) {
    std::vector<int> diagonals;
    int length = nums.size();
    for (int i = 0; i < length; ++i) {
        diagonals.push_back(nums[i][i]);
        diagonals.push_back(nums[i][length - i - 1]);
    }
    return diagonals;
}

    int diagonalPrime(vector<vector<int>>& nums) {
    std::vector<int> diagonals = extract_diagonals(nums);
    int largest_prime = 0;
    for (int num : diagonals) {
        if (is_prime(num) && num > largest_prime) {
            largest_prime = num;
        }
    }
    return largest_prime;
}
    
};
