# 这是pta的第1003题，题目的名字叫我要通过
from this import d
from tkinter.messagebox import YES
from matplotlib.pyplot import flag


def main():
    n = int(input("请输入您需要验证的个数:"))
    res = []
    while (n):
        # 用来标志字符中是否出现了除了规定字符的数字
        # 用来判定目前已经读取到什么位置0,1,2
        flag = 1
        flag_place = 0
        words = str(input())
        lenth = len(words)
        A_P, A, A_T = 0, 0, 0
        num_P, num_T = 0, 0
        for i in range(lenth):
            if flag_place == 0:
                if words[i] == 'P':
                    num_P = num_P + 1
                    flag_place = 1
                elif words[i] == 'A':
                    A_P = A_P + 1
                else:
                    flag = 0
            elif flag_place == 1:
                if words[i] == 'T':
                    num_T += 1
                    flag_place = 2
                elif words[i] == 'A':
                    A = A + 1
                else:
                    flag = 0
            elif flag_place == 2:
                if words[i] == 'A':
                    A_T = A_T + 1
                else:
                    flag = 0
            print(i, flag)
        if flag and A > 0 and num_P == 1 and num_T == 1 and A_P == A * A_T:
            res.append(1)
        else:
            # print(A)
            res.append(0)
        n = n - 1
    lenth = len(res)
    for i in range(lenth):
        # print(res[i])
        if res[i] == 1:
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    main()