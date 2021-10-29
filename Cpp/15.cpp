class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int lenth = nums.size();
        sort(nums.begin(),nums.end());
        int first;
        for(first = 0;first < lenth;first ++) {
            if(first > 0 && nums[first] == nums[first-1]) {
                continue;
            }
            int third = lenth - 1;
            int second;
            int target = -nums[first];
            for(second = first + 1;second < lenth;second ++) {
                if(second > first + 1 && nums[second] == nums[second-1]) {
                    continue;
                }
                while(second < third && nums[second] + nums[third] > target) {
                    third --;
                }
                if(third == second) {
                    break;
                }
                if(nums[second] + nums[third] == target) {
                    res.push_back({nums[first],nums[second],nums[third]});
                    //temp.push_back(nums[first]);
                    //temp.push_back(nums[second]);
                    //temp.push_back(nums[third]);
                    //res.push_back(temp);
                }
            }
        }
        return res;
    }
};