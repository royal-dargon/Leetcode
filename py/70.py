# 本题是实现一个计算爬楼梯的解决方案
class Solution:
    def climbStairs(self, n: int):
        dp = [0 for i in range(n)]
        if n == 1 or n == 2:
            return n
        dp[0] = 1
        dp[1] = 2
        for i in range(2,n):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n-1]


def main():
    res = Solution().climbStairs(5)
    print(res)


if __name__ == "__main__":
    main()