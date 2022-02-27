class Node:
    def __init__(self):
        self.minval = 1e4
        self.maxval = 0
        self.minstr = ""
        self.maxstr = ""

def optimalDivision(nums:list[int]):
    n = len(nums)
    dp = [[Node() for _ in range(n)] for _ in range(n)]
    for i, num in enumerate(nums):
        dp[i][i].minval = num
        dp[i][i].maxval = num
        dp[i][i].minstr = str(num)
        dp[i][i].maxstr = str(num)
    for i in range(n):
        for j in range(n-i):
            for k in range(j, j+i):
                if dp[j][j+i].maxval < dp[j][k].maxval / dp[k+1][j+i].minval:
                    dp[j][j+i].maxval = int(dp[j][k].maxval / dp[k+1][j+i].minval)
                    if k + 1 == j + i:
                            dp[j][j + i].maxstr = dp[j][k].maxstr + "/" + dp[k + 1][j + i].minstr
                    else:
                            dp[j][j + i].maxstr = dp[j][k].maxstr + "/(" + dp[k + 1][j + i].minstr + ")"
                if dp[j][j + i].minval > dp[j][k].minval / dp[k + 1][j + i].maxval:
                        dp[j][j + i].minval = dp[j][k].minval / dp[k + 1][j + i].maxval
                        if k + 1 == j + i:
                            dp[j][j + i].minstr = dp[j][k].minstr + "/" + dp[k + 1][j + i].maxstr
                        else:
                            dp[j][j + i].minstr = dp[j][k].minstr + "/(" + dp[k + 1][j + i].maxstr + ")"
    return dp[0][n - 1].maxstr

def main():
    res = optimalDivision(nums=[100,100,10,2])
    print(res)


if __name__ == "__main__":
    main()