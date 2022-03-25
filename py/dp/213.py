# 这是由动态规划实现的打家劫舍的进阶版
class Solution:
    def rob(self, nums: list[int]):
        # 这道题本质上就是添加了一些限定的条件
        n = len(nums)
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])
        return max(self.robRange(0, n-2, nums), self.robRange(1, n-1, nums))

    def robRange(self, start:int, end:int, nums: list[int]):
        first = nums[start]
        second = max(nums[start], nums[start+1])
        for i in range(start+2, end+1):
            q = first + nums[i]
            first = second
            second = max(q, second)
        return second

nums = [1,2,3,1]
print(Solution().rob(nums))