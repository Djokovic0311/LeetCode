class Solution:
    def minOperations(self, n: int) -> int:
        bin_n = str(bin(n))[2:]
        zero_count = bin_n.count('0')
        one_count = len(bin_n) - zero_count
        dp = [0] * (n*2 + 1)
        dp[1] = 1
        dp[2] = 1
        if n <= 2: return dp[n]
        # print(bin_n)
        for i in range(3,n*2):
            if not(i & (i - 1)):
                dp[i] = 1
                
        twice = 2
        for i in range(3,n+1):
            if not(i & (i - 1)):
                twice = i
            else:
                # print(dp[twice*2], dp[twice*2-i])
                dp[i] = min(dp[twice] + dp[i-twice], dp[twice*2] + dp[twice*2-i])
            # print(i, dp[i])
                
        return dp[n]

        
