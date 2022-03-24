# 这是通过动态规划进行完成的爬楼梯问题
class Solution:
    def climbStairs(self, n :int):
        if n == 1:
            return 1
        if n == 2:
            return 2
        p, q, s = 1, 2, 0
        for i in range(3, n+1):
            s = p + q
            p = q
            q = s
        return s


print(Solution().climbStairs(100))