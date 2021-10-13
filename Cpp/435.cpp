// 这是LeetCode 435题 需要移动给定区间的最小的数量让剩下来的区间都是互相不重复的
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 这是第一种方法，主要是使用了动态规划，在这道题中问题的实质是求剩余区间不重复的最大数量
    // 超时！！！
    int eraseOverlapIntervals1(vector<vector<int> >& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int i,j;
        vector<int> f(n,1);
        for(i = 1;i < n;i ++) {
            for(j = 0;j < i;j ++) {
                if(intervals[j][1] <= intervals[i][0]) {
                    // 这里是很重要的地方，判断这个区间是否需要留下来
                    f[i] = max(f[i],f[j]+1);
                }
            }
        }
        int max = 0;
        for(i = 0;i < n;i ++) {
            if(f[i] > max) {
                max = f[i];
            }
        }
        return n-max;
    }
    // 这里使用了贪心的思想
    int eraseOverlapIntervals2(vector<vector<int> >& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto& u, const auto& v) {
            return u[1] < v[1];});
        int right = intervals[0][1];
        int ans = 1;
        int i;
        int n = intervals.size();
        for(i = 1;i < n;i ++) {
            if(intervals[i][0] >= right) {
                right = intervals[i][1];
                ans ++;
            }
        }
        return n-ans;
    }
};

int main()
{
    vector<int> value1,value2,value3;
    vector<vector<int> > intervals;
    value1.push_back(1);
    value1.push_back(2);
    value2.push_back(1);
    value2.push_back(2);
    value3.push_back(2);
    value3.push_back(3);
    intervals.push_back(value1);
    intervals.push_back(value2);
    intervals.push_back(value3);
    Solution tmp;
    int res = tmp.eraseOverlapIntervals1(intervals);
    int res1 = tmp.eraseOverlapIntervals2(intervals);
    cout<<res<<" "<<res1<<endl;
    return 0;
}