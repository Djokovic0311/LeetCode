class Solution {
public:
    int maxSumDivThree(vector<int>& vec) {
       vector<vector<int>> dp(vec.size() + 1, vector<int>(3));
   
       /* What does the first index mean? (i)
        *  It means we're currently looking at the subarray from 0 to i (exclusive).
        *
        * What does the second index mean? (j)
        *  It represents the remainder that we currently have.
        *
        * We want to find dp[N][0]. In other words, we want to find the greatest sum of the whole array, given that we have no remainder left to add, that is still divisible by 3.
        */
   
       dp[0][0] = 0; // our sum at this point is 0, and we have no remainder left to add. that gives us 0, which is divisible by 3, so 0 is a valid answer!
       dp[0][1] = INT_MIN; // our sum at this point is 0, and we have 1 remainder left to add. that gives us 1, which is not divisible by 3, and is invalid.
       dp[0][2] = INT_MIN; // same as above. 2 is not divisible by 3, which is invalid.

        
       for (unsigned int i = 1; i <= vec.size(); i++)
       {
           int ind = i-1;
           /* At every i, we have a choice.
            *
            *  1. Skip the element. So our answer is just our previous answer.
            *
            *  2. Add the element to our sum. If we add this element, that means our remainder will now be (num % 3).
            *  This won't give us a number that's fully divisible by 3 by itself, well, unless (num % 3) is 0.
            *
            *  The only way we can get one, is if we look at a state which is dependent on adding the remainder (num % 3) to get a number divisible by 3.
            *  Luckily, we can find one for the step right before us using dp[i-1][(vec[ind] % 3)]!
            */
           dp[i][0] = max(dp[i-1][0], dp[i-1][(vec[ind]) % 3] + vec[ind]);
   
           /* The same logic applies for 1 and 2.
            * We add 1 or 2 because we still need to count our outstanding remainder.
            *
            * In other words:
            *
            * If we're at dp[i][1], we're at the state where we have +1 remainder.
            * If we're at dp[i][2], we're at the state where we have +2 remainder.
            *
            * We combine that with the remainder we'll get when we add our element.
            */
           dp[i][1] = max(dp[i-1][1], dp[i-1][(vec[ind]+1) % 3] + vec[ind]);
           dp[i][2] = max(dp[i-1][2], dp[i-1][(vec[ind]+2) % 3] + vec[ind]);
       }
        
       return dp[vec.size()][0];
    }
};

