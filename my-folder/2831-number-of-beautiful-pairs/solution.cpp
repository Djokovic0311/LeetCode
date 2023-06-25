class Solution {
public:
    int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

    int countBeautifulPairs(vector<int>& nums) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int firstDigit = nums[i];
        while(firstDigit >= 10) {
            firstDigit /= 10;
        }
        for (int j = i + 1; j < n; j++) {
            int lastDigit = nums[j] % 10;
            if (gcd(lastDigit, firstDigit) == 1)
                count++;
        }
    }

    return count;
       
    }
};
