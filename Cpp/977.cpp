#include <vector>
#include <algorithm>

using namespace std;


// 可以直接排序的方式
// 有点拉胯，没有运用到题目给的另一个条件
class Solution1 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> temp1;
        vector<int> temp2;
        vector<int> res;
        int i,j;
        for(i = 0;i < nums.size();i ++) {
            if(nums[i] < 0) {
                temp1.push_back(nums[i]*nums[i]);
            } else {
                temp2.push_back(nums[i]*nums[i]);
            }
        }
        sort(temp1.begin(),temp1.end());
        i = 0;
        j = 0;
        while(i < temp1.size() && j < temp2.size()) {
            if(temp1[i] < temp2[j]) {
                res.push_back(temp1[i]);
                i ++;
            } else {
                res.push_back(temp2[j]);
                j ++;
            }
        }
        while(i < temp1.size()) {
            res.push_back(temp1[i]);
            i ++;
        }
        while(j < temp2.size()) {
            res.push_back(temp2[j]);
            j ++;
        }
        return res;
    }
};