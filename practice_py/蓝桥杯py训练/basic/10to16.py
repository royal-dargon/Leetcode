# 本题需要实现的目标是十进制向十六进制的转换
n = int(input())
res = hex(n).upper()
print(res[2:])