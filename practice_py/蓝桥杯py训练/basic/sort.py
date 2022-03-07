def main():
    n = int(input())
    nums = []
    list = input().split()
    for i in range(n):
        nums.append(int(list[i]))
    nums.sort()
    for num in nums:
        print(num, end=" ")


if __name__ == "__main__":
    main()