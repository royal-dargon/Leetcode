// Leetcode 119题 杨辉三角 输入行数 返回该行的数字
#include <iostream>
#include <vector>

using namespace std;

// 方法一 递归但是超时了 哈哈哈
/*
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i;
        vector<int> res;
        for(i = 0;i <= rowIndex;i ++) {
            if(i == 0||i == rowIndex) {
                res.push_back(1);
            } else {
                vector<int> temp;
                temp = this->getRow(rowIndex-1);
                res.push_back(temp[i-1]+temp[i]);
            }
        }
        return res;
    }
};
*/
// 那只好试试别的方法啦
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > temp(rowIndex+1);
        int i;
        for(i = 0;i <= rowIndex;i ++) {
            int j;
            temp[i].resize(i+1);
            temp[i][0] = temp[i][i] = 1;
            for(j = 1;j < i;j ++) {
                temp[i][j] = temp[i-1][j-1] + temp[i-1][j];
            }
        }
        return temp[rowIndex];
    }
};

int main()
{
    vector<int> res;
    Solution tmp;
    res = tmp.getRow(11);
    int i;
    for(i = 0;i < res.size();i ++) {
        cout<<res[i]<<" ";
    }
    return 0;
}