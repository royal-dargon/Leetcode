// Leetcode 75题 颜色分类 0,1,2分类 题目要求是采用一个原地排序的方式
// 这里我采用的办法是快速排序
#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& nums,int low,int high) {
    int temp = nums[low];
    while(low<high) {
        while(low < high && temp <= nums[high]) {
            high --;
        }
        if(low < high && temp > nums[high]) {
            nums[low] = nums[high];
            low ++;
        }
        while(low < high && temp >= nums[low]) {
            low ++;
        }
        if(low < high && temp < nums[low]) {
            nums[high] = nums[low];
            high --;
        }
    }
    nums[low] = temp;
    return low;
}

void Sort(vector<int>& nums,int low,int high) {
    if(low < high) {
        int res = Partition(nums,low,high);
        Sort(nums,low,res-1);
        Sort(nums,res+1,high);
    }
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lenth = nums.size();
        Sort(nums,0,lenth-1);
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(0);
    //nums.push_back(1);
    //nums.push_back(0);
    //nums.push_back(1);
    Solution tmp;
    tmp.sortColors(nums);
    int i;
    for(i = 0;i < nums.size();i ++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
