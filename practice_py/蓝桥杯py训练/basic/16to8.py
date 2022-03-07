# 这道题目的要求是实现一个十六进制的正整数转换成八进制的功能
def main():
    n = int(input())
    nums = []
    for i in range(n):
        num = input()
        nums.append(num)
    for i in range(n):
        nums[i] = Solution(nums[i])
    for num in nums:
        print(num)


# 用来实现转换的函数
def Solution(num):
    # 这行代码的意思是把一个十六进制的数字转换成十进制
    res_1 = int(num, 16)
    res_2 = oct(res_1)
    return res_2[2:] 




if __name__ == "__main__":
    main()