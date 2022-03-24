# 第N个泰波那契数
class Solution:
    # 这种方法存在超时的问题
    def tribonacci1(self, n: int):
        if n == 1 or n == 2:
            return 1
        if n == 0:
            return 0
        return self.tribonacci1(n-1) + self.tribonacci1(n-2) + self.tribonacci1(n-3) 


    # 这种方法是题解中给出的求解方式
    def tribonacci2(self, n: int):
        if n == 0:
            return 0
        if n <= 2:
            return 1
        p, q, r, s = 0, 1, 1, 1
        for i in range(3, n+1):
            s = p + q + r
            p = q
            q = r
            r = s
        return s


def main():
    n = 30
    res = Solution().tribonacci2(n)
    print(res)


if __name__ == "__main__":
    main()