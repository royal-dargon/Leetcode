#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>

using namespace std;

#define TRUE 1
#define FALSE 0
//const STACK_INIT_SIZE=100;
//const STACKINCREMENT=10;
int maxsize = 100;
int incresize = 100;

typedef int ElemType;
typedef struct{
	ElemType *elem;
	int top;
	int stacksize;
	int incrementsize;
}Sq_Stack;

void InitStack_Sq(Sq_Stack &S) 
{
	
	S.elem = new ElemType[maxsize];
	S.top = -1;
	S.stacksize = maxsize;
	S.incrementsize = incresize;
}

void Push_Sq(Sq_Stack &S, ElemType e)
{
//	if(S.top==S.stacksize-1) incrementStacksize(S); 追加
	S.elem[++S.top] = e;
}

bool Pop_Sq(Sq_Stack &S, ElemType &e)
{
	if(S.top == -1) {
        return FALSE;
    } 
	e = S.elem[S.top--];
	return TRUE;
}

bool StackEmpty_Sq(Sq_Stack S)
{
   if(S.top == -1) {
        return true;
   } else {
        return false;
   }
}

void StackTraverse_Sq(Sq_Stack S)
{

	//ElemType *p;
	int i;
	//p = S.elem;
	cout << "找到一组解（物品的序号）：";
	for(i = 0;i <= S.top;i ++)
	{
		//printf("%d ",*p);
		//p++;
        cout << S.elem[i] + 1 << " ";
	}
}

void knapsack(int *w, int T, int n)
{
	int k = 0;
	Sq_Stack S;
	InitStack_Sq(S);
	do{
		while(T > 0 && k < n)
		{
			if(T-w[k] >= 0)
			{
				Push_Sq(S,k);
				T -= w[k];
			}
			k++;
		}
		if(T == 0) {
            StackTraverse_Sq(S);
        }  
		Pop_Sq(S,k);
		T += w[k];
		k ++;
	} while (!StackEmpty_Sq(S) || (k < n));
}

int main() {
	int T, i, n;
	cout << "请输入物品个数：";
	cin >> n;
	int* w=(int*)malloc(sizeof(int)*maxsize); 
	for(i = 0;i < n;i ++) {
		cout << "第"<<i+1 << "物品的体积=：";
		cin >> w[i];
	}
	cout << "请输入背包个数：";
	cin >> T;
	knapsack(w, T, n);
    return 0;
}