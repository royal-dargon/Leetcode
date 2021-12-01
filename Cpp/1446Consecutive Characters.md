### 1446 连续字符串
#### 思路
遍历一遍字符串，然后对每个字符进行下一个进行匹配，如果发现有一样的就开始增加记录数字的大小，如果发现不是连续的那么就开始将记录同时变为1
#### 代码
```
class Solution {
public:
    int maxPower(string s) {
        int lenth = s.size();
        int i, count = 1;
        int res = 1;
        //cout << lenth << endl;
        for(i = 0;i < lenth - 1;i ++) {
            if(s[i] == s[i+1]) {
                count ++;
            } else {
                if(res < count) {
                    res = count;
                    count = 1;
                } else {
                    count = 1;
                }
            }
        }
        if(res < count) {
            res = count;
        }
        return res;
    }
};
```