# 这道题是最简单的斐波那契数列
class Solution:
    def fib(self, n: int):
        if n == 0:
            return 0
        if n == 1:
            return 1
        p, q, s = 0, 1, 1
        for i in range(2, n+1):
            s = p + q
            p = q
            q = s
        return s


res = Solution().fib(10)
print(res)