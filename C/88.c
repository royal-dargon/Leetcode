#include <stdio.h>
#include <stdlib.h>

// 这是我的初步解题方式
// 先合并然后排序
void merge1(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i;
    int j = 0;
    for(i = m;i < m+n;i ++)
    {
        nums1[i] = nums2[j];
        j ++;
    }
    for(i = 0;i < n+m-1;i ++){
        for(j = 0;j < n+m-1;j ++)
        {
            if(nums1[j]>nums1[j+1])
            {
                int temp = nums1[j];
                nums1[j] = nums1[j+1];
                nums1[j+1] = temp;
            }
        }
    }
}

// 这也是一个排序的方式利用了C语言的qsort()
/*
int cmp(int* a, int* b){
    return *a - *b;
}
void merge2(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i;
    for(i = 0;i != n; ++i){
        nums1[m+i] = nums2[i];
    }
    qsort(nums1,nums1Size,sizeof(int),cmp);
}
*/

// 这个方法使用的是双指针的算法
void merge3(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int p1 = 0;
    int p2 = 0;
    int i = 0;
    int* nums;
    nums = (int*)malloc(sizeof(int)*(m+n));
    while(p1 < m && p2 < n)
    {
        if(nums1[p1] < nums2[p2])
        {
            nums[i] = nums1[p1];
            p1 ++;
            i ++;
        } else {
            nums[i] = nums2[p2];
            p2 ++;
            i ++;
        }
    }
    while (p1 < m)
    {
        nums[i] = nums1[p1];
        i ++;
        p1 ++;
    }
    while(p2 < n)
    {
        nums[i] = nums2[p2];
        p2 ++;
        i ++;
    }
    for(i = 0;i < m+n;i ++)
    {
        nums1[i] = nums[i];
    }
    
}

int main()
{
    int i;
    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};
    merge3(nums1,6,3,nums2,3,3);
    for(i = 0;i < 6;i ++)
    {
        printf("%d ",nums1[i]);
    }
    return 0;
}