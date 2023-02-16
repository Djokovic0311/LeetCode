class Solution:
    def maximumProfit(self, present: List[int], future: List[int], budget: int) -> int:
        dp = [0] * (budget+1)
        for p, f in zip(present, future):
            for i in range(budget,p-1,-1):
                # print(dp)
                dp[i] = max(dp[i], dp[i-p]-p+f)
        return dp[-1]
