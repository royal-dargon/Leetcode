# 蓝桥杯训练最短路径 本题因为存在负数的原因于是使用了spfa的算法
def Solution(n:int, dic:list):
    # 这是创建出来用来更新距离的列表
    vis = [float('inf') for i in range(n)]
    vis[0] = 0
    q = [0]
    while len(q):
        temp = q.pop(0)
        t = dic[temp]
        L = t.keys()
        for i in L:
            nl = vis[temp] + t[i]
            if nl < vis[i]:
                vis[i] = nl
                q.append(i)
    for i in range(1, n):
        print(vis[i])


if __name__ == "__main__":
    n, m = map(int,input().split())
    dic = [dict() for i in range(n)]
    for i in range(m):
        a, b, l = map(int, input().split())
        dic[a-1][b-1] = l
    Solution(n, dic)