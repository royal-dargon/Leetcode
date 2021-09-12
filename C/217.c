#include <stdio.h>
#include <stdlib.h>
// 本题是判断一个给定数组是否存在重复元素

// 这种方法是通过先排序然后进行判断
// 这个方法显然会超时
int containsDuplicate1(int* nums,int numsSize)
{   
    int i,j;
    for(i = 0;i < numsSize-1;i ++)
    {
        for(j = 0;j < numsSize-1;j++)
        {
            if(nums[j] < nums[j+1])
            {
                int temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }
    for(i = 0;i < numsSize-1;i ++)
    {
        if(nums[i] == nums[i+1])
        {
            return 1;
        }
    }
    return 0;
}

// 于是我们采取第二种排序方式
// 这种方式运用到了C语言的库函数stdlib.h中的qsort
// qsort中有四个参数需要填写分别是需要排序数组的指针，数组中元素的个数，数组中每个元素的大小，已经用来比较两数大小的函数
int cmp(const void* _a, const void* _b)
{
    int a = *(int*)_a;
    int b = *(int*)_b;
    return a-b;
}

int containsDuplicate2(int* nums,int numsSize)
{
    int i;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(i = 0;i < numsSize-1;i ++)
    {
        if(nums[i] == nums[i+1])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int num[4] = {1,2,3,1};
    int res;
    res = containsDuplicate2(num,4);
    printf("%d",res);
}