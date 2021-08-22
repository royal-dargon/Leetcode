#include <stdio.h>
#include <string.h>

char* convert(char *s, int numRows);

int main()
{
    char* p = "paypalishiring";
    char* res = convert(p,3);
    printf("%s",res);
}

char* convert(char *s, int numRows)
{
    int i,j;
    int count = 0;
    int lenth = strlen(s);
    int temp;
    char* res;
    char str[10000];
    temp = numRows*2 - 2;
    for(i = 0;i <= (temp+1)/2;i ++)
    {
        for(j = 0;j < lenth;j ++)
        {
            if(j%temp==i||j%temp==temp-i){
                str[count++] = s[j];
            }
        }
    }
    res = str;
    printf("%c",res[1]);
    return res;
}