# 这道题是买股票的最佳时机，题目的提示是使用动态规划的手段进行解题
class Solution:
    # 这个方法是出现了超时的问题
    def maxProfit(self, prices: list[int]):
        max = 0
        n = len(prices)
        dp = [[0 for j in range(n)] for k in range(n)]
        for i in range(n):
            for j in range(i+1, n):
                if prices[i] <prices[j]:
                    dp[i][j] = prices[j] - prices[i]
                    if max < dp[i][j]:
                        max = dp[i][j]
        return max
    # 下面一个办法的思路是先遍历一遍prices从中获得最小的数据 然后就可以假设股票是天天在那一天买的？？？有问题的官方解答
    def maxProfit2(self, prices: list[int]):
        max = 0
        n = len(prices)
        dp = [0 for i in range(n)]
        dp[0] = prices[0]
        for i in range(1, n):
            if prices[i] > dp[i-1]:
                temp = prices[i] - dp[i-1]
                if max < temp:
                    max = temp
                dp[i] = dp[i-1]
            else:
                dp[i] = prices[i]
        return max

def main():
    res = Solution().maxProfit2([7,1,5,3,6,4])
    print(res)


if __name__ == "__main__":
    main()