/*
本题是一个窗口滑动的形式，滑动时减去末尾增加一个进入窗口的数字
*/
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int lenth1 = s1.size();
        int lenth2 = s2.size();
        if(lenth1 > lenth2) {
            return false;
        }
        int a[26],b[26];
        memset(a,0,sizeof(int)*26);
        memset(b,0,sizeof(int)*26);
        for(int i = 0;i < lenth1;i ++) {
            a[s1[i] - 'a'] ++;
        }
        // 开始初始化第一次的数据
        int j;
        for(j = 0;j < lenth1;j ++) {
            b[s2[j] - 'a'] ++;
        }
        // 用来表示窗口的最左侧
        int temp = 0;
        // 开始比对
        j = j - 1;
        cout <<j;
        while(j < lenth2) {
            int i = 0;
            for(i = 0;i < lenth1;i ++) {
                if(a[i] != b[i]) {
                    break;
                }
            }
            if(i == lenth1) {
                return true;
            }
            j ++;
            if(j < lenth2) {
                b[s2[temp] - 'a'] --;
                b[s2[j] - 'a'] ++;
                temp ++;
            }
        }
        return false;
    }
};