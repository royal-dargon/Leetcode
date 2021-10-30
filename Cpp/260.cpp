class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        int i;
        for(i = 0;i < nums.size();i ++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            if(i < nums.size()-1 && nums[i] == nums[i+1]) {
                continue;
            }
            res.push_back(nums[i]);
        }
        return res;
    }
};