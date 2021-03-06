#### 一些做题的总结
##### dp 类型的问题
* 1180 秘密行动
  这道题目主要的思路是将每次进行到的位置进行了一个状态的划分。如果这次可以进行跳跃的话，前面一次就是爬上来的，那么爬到这个高度的情况就可以分为两种，一种是跳跃前一个位置加上到达这个高度的距离，或者是爬到前一个位置，再进行攀爬的。第二种就是此时不可以跳跃，那么就是前一次发生了跳跃的两种情况进行比较。
  
  ```python
  dp1[i] = min(dp2[i-1] + highs[i], dp1[i-1] + highs[i])
  dp2[i] = min(dp1[i-1], dp1[i-2])
  ```
  
* 1173 学生节

  这个问题类似于背包问题，就是在n个商品中选择出价值最高的m个，同时本问题的变种部分在于做的时候需要去注意是有一个最迟时间的限制，因此我们选择了一个dp的二维数组进行存储，表示的是在n个节目中选取价值最高的m个的大小。

  ```python
  for i in range(1, n+1):
      for j in range(1, n+1):
          dp[i][j] = max(dp[i-1][j-1] + v[i-1], dp[i-1][j])
  ```

  状态的变化分为两种，一种是这次的价值是很大的，另一个便是这一次的价值是不需要添加进去的。
