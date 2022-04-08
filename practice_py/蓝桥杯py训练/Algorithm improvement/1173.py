# n, m, k 分别表示三个数字分别是共有n个节目，最多看m个节目，有k个最迟的时间
n, m, k = map(int,input().split())
# 下面开始获取节目的价值
v = [0 for _ in range(n)]
for i in range(n):
    v[i] = int(input())
# 下面开始获取最晚时间的节目号
ti = [0 for _ in range(k)]
for i in range(k):
    ti[i] = int(input())

dp = [[0 for _ in range(n+1)] for _ in range(n+1)]
for i in range(1, n+1):
    for j in range(1, n+1):
        dp[i][j] = max(dp[i-1][j-1] + v[i-1], dp[i-1][j])


res = [0 for _ in range(k)]
for i in range(k):
    res[i] = dp[ti[i]][m]

for i in range(k):
    print(res[i])