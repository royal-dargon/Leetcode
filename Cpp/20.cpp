// LeetCode 20 有效括号
#include <iostream>
using namespace std;

class Stack{
    public:
        char *elem;
        int top;
    Stack() {
        top = -1;
        elem = new char[10000];
    }
    char Pop_stack();
    void Push_stack(char s);
    bool IsEmpty() {
        if(top == -1)
        {
            return true;
        } else {
            return false;
        }
    }
};

class Solution{
    public:
        bool isValid(string s) {
            Stack str;
            int lenth = s.size();
            int i;
            for(i = 0;i < lenth;i ++) {
                if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                    str.Push_stack(s[i]);
                } else {
                    char tmp = str.Pop_stack();
                    if(s[i] == ')')
                    {
                        if(tmp != '(')
                            return false;
                    }
                    else if(s[i] == '}')
                    {
                        if(tmp != '{')
                            return false;
                    } else {
                        if(tmp != '[')
                            return false;
                    }
                }
            }
            bool res = str.IsEmpty();
            return res;
        }
};

int main()
{
    Solution s;
    string tmp = "({[]})";
    bool res = s.isValid(tmp);
    cout<<res;
    return 0;
}

char Stack::Pop_stack() {
    if(top == -1)
    {
        char res = '1';
        return res;
    } else {
        char res = elem[top];
        top = top - 1;
        return res;
    }
}

void Stack::Push_stack(char s) {
    top = top + 1;
    elem[top] = s;
}