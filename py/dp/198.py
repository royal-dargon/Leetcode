# 这是利用动态规划解决的打家劫舍问题
class Solution:
    def rob(self, nums: list[int]):
        n = len(nums)
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])
        dp = [0 for i in range(n)]
        dp[0] = nums[0]
        dp[1] = max(nums[1], nums[0])
        for i in range(2, n):
            dp[i] = max(dp[i-1], dp[i-2]+nums[i])
        return dp[n-1]


nums = [1,2,3,1]
print(Solution().rob(nums))