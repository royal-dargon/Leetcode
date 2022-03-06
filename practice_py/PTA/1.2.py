# 这是pta的第二题
def Solution():
    a, b, c = input("请输入数字A和B:").split()
    res = int(b) * int(b) - 4 * int(a) * int(c)
    return res

def main():
    res = Solution()
    print(res)


if __name__ == "__main__":
    main()