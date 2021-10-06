#include <stdio.h>
#include <stdlib.h>

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
int cmp(const void* _a, const void* _b)
{
    int a = *(int*)_a;
    int b = *(int*)_b;
    return a-b;
}

int main()
{
    int nums[] = {-1,0,1,2,-1,-4};
    int n = sizeof(nums)/sizeof(int);
    int *returnSize;
    int **returnColumnSizes;
    int **res = threeSum(nums,n,returnSize,returnColumnSizes);
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums,numsSize,sizeof(int),cmp);
    int i,j;
    int resNumber = 0;
    for(i = 0;i < numsSize-2 ;i++)
    {
        for(j = i+1;j < numsSize-1;j ++)
        {
            
        }
    }
}