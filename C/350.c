#include <stdio.h>
#include <stdlib.h>

// 本题是对给定的两个数组进行合并，计算出它们的交集
int cmp(const void* a,const void* b)
{
    return *(int*)a - *(int*)b;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    qsort(nums1,nums1Size,sizeof(int),cmp);
    qsort(nums2,nums2Size,sizeof(int),cmp);
    int l1 = 0,l2 = 0;
    int count = 0;
    int* res;
    res = (int*)malloc(sizeof(int)*(nums1Size+nums2Size));
    while(l1<nums1Size&&l2<nums2Size){
        if(nums1[l1] < nums2[l2])
        {
            l1 ++;
        }
        else if(nums1[l1] > nums2[l2])
        {
            l2 ++;
        } else {
            res[count++] = nums1[l1];
            l1 ++;
            l2 ++;
            (*returnSize) ++;
        }
    }
    return res;
}

int main(){
    int nums1[] = {1,2,2,1};
    int nums2[] = {2,2};
    int size = 0;
    int i;
    int* a = intersect(nums1,4,nums2,2,&size);
    for(i = 0;i < size;i ++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}