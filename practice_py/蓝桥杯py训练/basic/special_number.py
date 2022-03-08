# 本题的目标是要去构建一组回文数在这个数字中各位之和等于输入的值，同时位数为五或者六
def main():
    n = int(input())
    for i in range(10000, 1000000):
        nums = str(i)
        result = 0
        if nums == nums[::-1]:
            for num in nums:
                result += int(num)
        if result == n:
            print(nums)


if __name__ == "__main__":
    main()