# 这是一道可以通过动态规划进行解决的问题
# n是表示的是输入的楼层数
n = int(input())
# 下面将会输入n个数字，表示的是层的高度
highs = []
for i in range(n):
    k = int(input())
    highs.append(k)
# 下面我们希望设置两个dp，分别为dp1,dp2
# dp1 表示的状态是目前是可以跳的， dp2 表示的状态是目前不可以跳的
if n > 1:
    dp1 = [0 for _ in range(n)]
    dp2 = [0 for _ in range(n)]
    dp1[0] = highs[0]
    dp2[0] = 0
    dp1[1] = dp2[0] + highs[1]
    dp2[0] = 0
    for i in range(2, n):
        dp1[i] = min(dp2[i-1] + highs[i], dp1[i-1] + highs[i])
        dp2[i] = min(dp1[i-1], dp1[i-2])

    print(min(dp1[n-1], dp2[n-1]))
else:
    print("0")