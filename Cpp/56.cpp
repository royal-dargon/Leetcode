// Leetcode 第五十六题 合并区间 合并所有的重复区间 并返回一组不重复的区间
#include <iostream>
#include <vector>
#include <algorithm>   

using namespace std;


class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > res;
        if(intervals.size() == 0) {
            return res;
        }
        sort(intervals.begin(),intervals.end());
        int i;
        for(i = 0;i < intervals.size();i ++) {
            if(i == 0) {
                vector<int> temp;
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
                res.push_back(temp);
            }
            if(i != 0) {
                vector<int> temp;
                if(res.back()[1] < intervals[i][0]) {
                    temp.push_back(intervals[i][0]);
                    temp.push_back(intervals[i][1]);
                    res.push_back(temp);
                } else {
                    res.back()[1] = max(intervals[i][1],res.back()[1]);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution tmp;
    vector<vector<int> > intervals;
    vector<int> value1,value2,value3;
    value1.push_back(1);
    value1.push_back(4);
    value2.push_back(3);
    value2.push_back(5);
    value3.push_back(4);
    value3.push_back(7);
    intervals.push_back(value1);
    intervals.push_back(value2);
    intervals.push_back(value3);
    int i,j;
    vector<vector<int> > res = tmp.merge(intervals);
    for(i = 0;i < res.size();i ++) {
        cout<<"[ ";
        for(j = 0;j < res[i].size();j ++) {
            cout<<res[i][j]<<" ";
        }
        cout<<"]";
    }
    return 0;
}