//704 二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lenth = nums.size();
        int flagr = lenth-1;
        int flagl = 0;
        while(flagl <= flagr) {
            int temp = flagl + flagr;
            temp = temp / 2;
            if(nums[temp] == target) {
                return temp;
            } 
            else if(nums[temp] < target) {
                flagl = temp+1;
            } else {
                flagr = temp-1;
            }
        }
        return -1;
    }
};