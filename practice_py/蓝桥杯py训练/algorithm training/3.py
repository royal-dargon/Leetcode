# 这道题目主要需要实现的目标是一个k好数
K, L = input().split()
K = int(K) 
L = int(L)
dp = [[0 for i in range(K)] for j in range(L)]
for i in range(L):
    for j in range(K):
        if i == 0:
            dp[i][j] = 1
        else:
            for m in range(K):
                if m != j-1 and m != j + 1:
                    dp[i][j] += dp[i-1][m]
res = 0
for k in range(1,K):
    res += dp[L-1][k]
res = res % 1000000007
print(res)