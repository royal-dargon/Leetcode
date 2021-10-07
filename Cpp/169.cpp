// Leetcode 169题 多数元素，就是一个数字在n个数字出现超过n/2次 题目默认必然存在多数元素
#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int, int> counts;
        int lenth = nums.size();
        int i;
        int majority = 0, cnt = 0;
        for(i = 0;i < lenth;i ++) {
            counts[nums[i]] ++;
            if (counts[nums[i]] > cnt) {
                majority = nums[i];
                cnt = counts[nums[i]];
            }
        }
        return majority;
    }
};

int main()
{
    vector<int> nums;
    Solution tmp;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(2);
    int res = tmp.majorityElement(nums);
    cout<<res<<endl;
    return 0;
}