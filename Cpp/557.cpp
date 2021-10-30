#include <iostream>
#include <string>

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int lenth = s.size();
        while(i < lenth) {
            int start = i;
            while(i < lenth && s[i] != ' ') {
                i ++;
            }
            int end = i - 1;
            while(start < end) {
                int temp = s[start];
                s[start] = s[end];
                s[end] = temp;
                end --;
                start ++;
            }
            while(i < lenth && s[i] == ' ') {
                i ++;
            }
        }
        return s;
    }
};