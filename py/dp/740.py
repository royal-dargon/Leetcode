# 这是利用动态规划实现的删除并获得点数的解决方案
class Solution:
    # 这道题在我看来与打家劫舍的本质上还是一样的，依旧是不允许相邻的元素进行添加
    def deleteAndEarn(self, nums: list[int]):
        p = max(nums)
        dp = [0 for i in range(p+1)]
        for num in nums:
            dp[num] += num
        if p == 1:
            return dp[1]
        if p == 2:
            return max(dp[1], dp[2])
        else:
            first = dp[1]
            second = max(dp[1], dp[2])
            for i in range(3, p+1):
                p = first + dp[i]
                first = second
                second = max(p, second)
        return second