#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        int lenth = nums.size();
        if(k >= lenth) {
            k = k % lenth;
        }
        int i;
        for(i = 0;i < k;i ++) {
            temp.push_back(nums[lenth-k+i]);
        }
        for(i = 0;i < lenth-k;i ++) {
            temp.push_back(nums[i]);
        }
        for(i = 0;i < lenth;i ++) {
            nums[i] = temp[i];
        }
    }
};