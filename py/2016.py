def Solution(nums:list[int]):
    n = len(nums)
    ans = -1
    premin = nums[0]
    for i in range(1,n):
        if nums[i] > premin:
            ans = max(ans, nums[i] - premin)
        else:
            premin = nums[i]
    return ans


def main():
    nums = [1,7,3,9,5,8]
    print(Solution(nums))


if __name__ == "__main__":
    main()