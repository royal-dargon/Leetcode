#include<stdio.h>
// 最大子序和
// 给定一个整数数组，找到一个具有最大和的连续子数组，返回其最大和

// 第一种方法使用了动态规划
// 假设nums数组的长度是n，下标从0到n-1
// 我们使用f(i)表示第i个数结尾的最大和，所以就存在考虑f(i-1)的大小了，于是产生了动态转移方程
/*
int maxSubArray1(int* nums, int numSize)
{
    // pre用来维护当前f(i)的f(i-1)的值
    int pre = 0, maxAns = nums[0];
    int i;
    for(i = 0;i < numSize; i++)
    {   
        pre = fmax(pre+nums[i],nums[i]);
        maxAns = fmax(maxAns,pre);
    }
    return maxAns;
}
*/

// 贪心算法
// 假如之前的和的大小是负数就可以抛弃
int maxSubArray2(int* nums, int numSize)
{
    int i;
    int maxRes = 0;
    int res[numSize];
    res[0] = nums[0];
    int pre = res[0];
    for(i = 1;i < numSize;i ++)
    {
        if(pre >= 0)
        {
            res[i] = pre + nums[i];
            pre = pre + nums[i];
        } else {
            pre = nums[i];
            res[i] = nums[i];
        }
    }
    for(i = 0;i < numSize-1;i ++)
    {
        if(maxRes < res[i])
        {
            maxRes = res[i];
        }
    }
    return maxRes;
}

/*
int maxSubArray3(int* nums, int numSize)
{

}
*/

int main()
{
    int nums[] = {1,2,3,4,5};
    //int i = maxSubArray1(nums,5);
    int j = maxSubArray2(nums,5);
    printf("%d\n",j);
    return 0;
}