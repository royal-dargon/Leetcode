# 这是pta的第五题计算分段函数
from time import sleep


x = float(input("请输入实数x:"))
if x == 0:
    print(f"f(0.0) = 0.0")
else:
    print(f"f({x:.1f}) = {1/x:.1f}")
