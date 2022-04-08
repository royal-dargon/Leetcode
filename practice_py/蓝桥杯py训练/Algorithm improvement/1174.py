n = int(input())
nums = input().split()
arr = []
for i in range(n):
    arr.append(int(nums[i]))
dp = [0 for _ in range(n)]
dp[0] = arr[0]
for i in range(1, n):
    if dp[i-1] <= 0:
        dp[i] = arr[i]
    else:
        dp[i] = dp[i-1] + arr[i]
print(max(dp))
