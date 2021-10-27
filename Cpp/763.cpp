// LeetCode 763题 划分字母区间
// 题目的意思是同一个字母最多出现在一个区间而且划分的数量要最大
#include <iostream>
#include <vector>
#include <string>

using namespace std;


// 解题的思路是先遍历一遍字符串得到同一个字母的最后一个的下标
class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector<int> res;
        }
};

int main() {
    Solution tmp;
    string str = "ababcbacadefegdehijhklij";
    vector<int> res = tmp.partitionLabels(str);
    for(int i = 0;i < res.size();i ++) {
        cout << res[i] << endl;
    }
    return 0;
}