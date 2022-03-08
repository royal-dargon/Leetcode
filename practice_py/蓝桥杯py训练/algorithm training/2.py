# 本题需要实现的目标是输入一个正整数从一到他选出三个数求出他们最最小的公倍数
n = int(input())
ans = 0
if n < 3:
    ans = 0
else:
    if n % 2 == 1:
        ans = n * (n-1) * (n-2)
    else:
        if n % 3 != 0:
            ans = n * (n-1) * (n-3)
        else:
            ans = (n-1) * (n-2) * (n-3)
print(ans)