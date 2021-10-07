// Leetcode 136题 求一串数字中只出现一次的数字,并且其他数字都是只出现两次
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int lenth = nums.size();
        int i;
        sort(nums.begin(),nums.end());
        for(i = 0;i < lenth - 1;i ++) {
            if(i == 0) {
                if(nums[i] != nums[i+1]) {
                    break;
                }
            } else {
                if(nums[i] != nums[i-1] && nums[i] != nums[i+1]) {
                    break;
                }
            }
        }
        return nums[i];
    }
};

int main() 
{
    Solution tmp;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    int res = tmp.singleNumber(nums);
    cout<<res<<endl;
    return 0;
}