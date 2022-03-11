# 这道题目的思路是给定一个括号序列然后输出这个括号序列可以有多少中补全的方式
def way(words:str):
    # 这里我的思路是判断一共有多少组的括号数
    left = 0
    right = 0
    for word in words:
        if word == '(':
            left += 1
        else:
            right += 1
    n = max(left, right)
    res = Solution().generate_list(n)
    return len(res)


# 发现自己现在的思路还是出现了些许的问题需要去解决
def New_way(words:str):
    n = len(words)
    dp = [[0 for i in range(n+1)]for j in range(n+1)]
    dp[0][0] = 1
    for i in range(1, n):
        if words[i] == '(':
            for j in range(1, n+1):
                dp[i][j] = dp[i-1][j-1]
        else:
            dp[i][0] = dp[i-1][0] + dp[i-1][1]
            for k in range(1, n):
                dp[i][k] = dp[i-1][k+1] + dp[i][k-1]
    for i in range(n+1):
        if dp[n][i]:
            return dp[n][i]
    return -1


# 这个函数是用来对给定的n生成括号的组合序列
class Solution:
    def generate_list(self, n:int):
        if n == 0:
            return [""]
        ans = []
        for c in range(n):
            for left in self.generate_list(c):
                for right in self.generate_list(n-c-1):
                    ans.append("({}){}".format(left, right))
        return ans



def main():
    words = "((()"
    res_l = New_way(words)
    words = words[:-1]
    for i in range(len(words)):
        if words[i] == "(":
            words[i] == ")"
        else:
            words[i] == "("
    res_r = New_way(words)
    res = res_l * res_r % 1000000007
    print(res)


if __name__ == "__main__":
    main()