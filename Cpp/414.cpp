// LeetCode 414题 寻找一串数组中的第三大数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
int maxbit(vector<int>& nums,int n)
{
    int i;
    int max = 0;
    for(i = 0;i < n;i ++) {
        if(nums[i] > max)
        {
            max = nums[i];
        }
    }
    while(max)
}
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int count = 1;
        int i;
        int lenth = nums.size();
        //cout<<nums[1]<<endl;
        sort(nums.begin(),nums.end());
        if(lenth < 3){
            return nums[lenth-1];
        }
        for(i = lenth-2;i >= 0;i --)
        {
            if(nums[i] != nums[i+1])
            {
                count ++;
            }
            if(count == 3)
            {
                break;
            }
        }
        if(count < 3)
        {
            return nums[lenth-1];
        }
        return nums[i];
    }
};

int main()
{
    Solution tmp;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    int res = tmp.thirdMax(nums);
    cout<<res;
    return 0;
}