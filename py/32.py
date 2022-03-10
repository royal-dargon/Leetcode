# 本题需要实现的目标是在给定的字符串中找到最长有效的括号子串的长度
class Solution:
    def longestValidParentheses(self, s: str):
        lenth = len(s)
        dp = [0 for i in range(lenth)]
        for i in range(lenth):
            if i > 0 and s[i] == ')':
                if s[i-1] == '(': 
                    if i == 1:
                        dp[i] = 2
                    else:
                        dp[i] = dp[i-2] + 2
                elif s[i-1] == ')':
                    if i - dp[i-1] - 1 >= 0:
                        if s[i-dp[i-1]-1] == '(' and i > 1:
                            dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2
        max = 0
        for i in range(lenth):
            if dp[i] > max:
                max = dp[i]
        return max


def main():
    res = Solution().longestValidParentheses("()")
    print(res)


if __name__ == "__main__":
    main()