// Leetcode 48题 旋转图像 将一个n*n的矩阵顺时针旋转90°
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};

int main()
{
    vector<vector<int> > res;
    Solution tmp;
    vector<int> value1,value2,value3;
    value1.push_back(1);
    value1.push_back(2);
    value1.push_back(3);
    value2.push_back(4);
    value2.push_back(5);
    value2.push_back(6);
    value3.push_back(7);
    value3.push_back(8);
    value3.push_back(9);
    tmp.rotate(res);
    int i,j;
    for(i = 0;i < res.size();i ++) {
        cout<<"[";
        for(j = 0;j < res[i].size();j ++) {
            cout<<res[i][j]<<",";
        }
        cout<<"[";
    }
    return 0;
}