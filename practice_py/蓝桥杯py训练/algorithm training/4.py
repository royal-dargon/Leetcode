# 算法训练的节点选择，有一棵n个节点的树，树上每个节点都有一个正整数权值
n = int(input())
l = list(map(int,input().split()))
l.insert(0,0)
dic = {}
for i in range(n-1):
    a, b = list(map(int, input().split()))
    dic[a] = dic.get(a, [])
    dic[b] = dic.get(b, [])
    dic[a].append(b)
    dic[b].append(a)

vis = [0 for _ in range(n+1)]
dp = [[0 for i in range(n+1)] for j in range(2)]

def dfs(u:int):
    vis[u] = 1
    for i in range(len(dic[u])):
        v = dic[u][i]
        if vis[v]:
            continue
        dfs(v)
        dp[1][u] += dp[0][v]
        dp[0][u] += max(dp[0][v], dp[1][v])
    dp[1][u] += l[u]

dfs(1)
print(max(dp[0][1], dp[1][1]))