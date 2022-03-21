# 安慰奶牛 题解的思路是采用最小生成树的策略
# 这道题目其实本质上就是要对每条路的权值进行一定的处理，将每个条边的两个端点的权重也算进去
vis = []
def main():
    n, m = map(int, input().split())
    l = []
    for i in range(n):
        k = input()
        l.append(int(k))
        vis.append(i)
    dic = []
    for _ in range(m):
        a, b, k = map(int, input().split())
        k = l[a-1] + l[b-1] + 2 * k
        tmp = []
        tmp.append(a-1)
        tmp.append(b-1)
        tmp.append(k)
        dic.append(tmp)
    # 需要对最小的点进行判断，找到最小的点作为过夜的地点
    min = l[0]
    for i in range(1, n):
        if min > l[i]:
            min = l[i]
    # 进行最小生成树的算法
    minRes = min + Kruscal(dic)
    print(minRes)


def Kruscal(dic):
    ans = 0
    dic.sort(key=(lambda x:x[2]))
    # print(dic)
    for i in range(len(dic)):
        x = find(dic[i][0])
        y = find(dic[i][1])
        # print(x,y)
        if x != y:
            getUnit(x, y)
            ans = ans + dic[i][2]
    return ans


# 用来寻找这个节点的根节点的函数
def find(x: int):
    while vis[x] != x:
        x = vis[x]
    return x


# 用来将两个不是一样的树的根节点变成一样的办法
def getUnit(x, y):
    vis[y] = x



if __name__ == "__main__":
    main()