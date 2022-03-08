# 这题主要的思路就是实现一个水仙花数
for i in range(100,1000):
    nums = str(i)
    res = 0
    for num in nums:
        res += pow(int(num), 3)
    if res == i:
        print(i)
