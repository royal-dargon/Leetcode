# 本题是算法训练中的区间k大数查询
# 这个输入的数字表示的是序列的长度
n = int(input())
list = input().split()
nums = []
res = []
# 将输入的序列转换成数字存放
for num in list:
    nums.append(int(num))
# 表示的是查询的个数
m = int(input())
# 下面输入的是l,r,k表示的是询问序列从左到右中第k大的数字是什么
for i in range(m):
    l, r, k = input().split()
    l = int(l)
    r = int(r)
    k = int(k)
    temp = nums[l-1:r]
    temp.sort(reverse=True)
    res.append(temp[k-1])
for r in res:
    print(r)