# 本题的目标是实现一个杨辉三角的效果
class Solution:
    def generate(self, numRows: int):
        dp = [[0 for i in range(numRows)] for k in range(numRows)]
        for i in range(numRows):
            if i == 0:
                dp[0][0] = 1
            else:
                for k in range(i+1):
                    if k == 0 or k == i:
                        dp[i][k] = 1
                    else:
                        dp[i][k] = dp[i-1][k] + dp[i-1][k-1]
        res = []
        for i in range(numRows):
            temp = []
            for k in range(i+1):
                temp.append(dp[i][k])
            res.append(temp)    
        return res

def main():
    res = Solution().generate(1)
    print(res)

if __name__ == "__main__":
    main()