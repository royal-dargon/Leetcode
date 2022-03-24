# 这是动态规划的相关练习的使用最小花费爬楼梯的问题
class Solution:
    def minCost(self, cost: list[int]):
        n = len(cost)
        dp = [0 for i in range(n+1)]
        if n == 2:
            if cost[1] > cost[0]:
                dp[n] = cost[0]
            else:
                dp[n] = cost[1]
        for i in range(2, n+1): 
            if cost[i-2] + dp[i-2] > cost[i-1] + dp[i-1]:
                dp[i] = cost[i-1] + dp[i-1]
            else:
                dp[i] = cost[i-2] + dp[i-2]
        return dp[n]


cost = [0,2,2,1]
print(Solution().minCost(cost))