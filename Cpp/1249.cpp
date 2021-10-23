// Leetcode第1249题，题目的意思是删除最少的括号让剩下的字符串形成有效的括号
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Stack {
    int *elem;
    int top;
};

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        struct Stack temp;
        temp.top = -1;
        temp.elem = new int[s.size()];
        int *move;
        move = new int[s.size()];
        int MoveCount = 0;
        int i;
        for(i = 0;i < s.size()-1;i ++) {
            if(s[i] == '(') {
                temp.top = temp.top + 1;
                temp.elem[temp.top];
            }
            if(s[i] == ')') {
                if(temp.top == -1) {
                    move[MoveCount] = i;
                    MoveCount ++;
                } else {
                    temp.top --;
                }
            }
        }
        if(temp.top != -1) {
            while(temp.top != -1) {
                move[MoveCount] = temp.elem[temp.top];
                temp.top --;
                MoveCount ++;
            }
        }
        // 下面是按照刚刚所得需要删除的字符的数组进行处理.
        //sort(move.begin(),move.end());
        int count = 0,j = 0;
        char res[10000];
        for(i = 0;i < s.size()-1;i ++) {
            if(i != move[j]) {
                res[count++] = s[i]; 
            } else {
                j ++;
            }
        }
        char res1[count];
        strncpy(res1,res,count);
        string res2 = res1;
        return res2;
    }
};

int main() {
    string str = "le(e(t(c)o())de)";
    Solution tmp;
    string res = tmp.minRemoveToMakeValid(str);
    cout<<res<<endl;
    return 0;
}