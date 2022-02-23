def solution(nums: list[int], target: int):
    n = len(nums)
    for i in range(n):
        for j in range(i+1, n):
            if nums[i] + nums[j] == target:
                return [i, j]
    return []

nums = [1,3,5,9]
target = 4

if __name__ == "__main__":
    result = solution(nums,target)
    print(result)