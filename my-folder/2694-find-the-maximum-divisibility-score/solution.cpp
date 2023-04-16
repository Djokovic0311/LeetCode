class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
    int maxScore = 0;
    int maxDivisor = 0;

    for (int divisor : divisors) {
        int score = 0;
        for (int num : nums) {
            if (num % divisor == 0) {
                score++;
            }
        }

        if (score > maxScore || (score == maxScore && divisor < maxDivisor)) {
            maxScore = score;
            maxDivisor = divisor;
        }
    }

    return maxDivisor==0?*min_element(divisors.begin(), divisors.end()):maxDivisor;        
    }
};
