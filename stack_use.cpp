#include<iostream>
#include<vector> 
#include<cstring>
#include<string>
#include<stack>

using namespace std;

// ����ֵ�ǿյ�ָ�� 
int top = -1;

// ���ջ��Ԫ�� 
void clear(){
	top = -1;
}

// ��ȡջ�ڵ�Ԫ�صĸ���
int size() {
	return top+1;
}

//�ж��ǲ��ǿյ� 
bool empty() {
	if(top == -1) return true;
	else return false;
}

//
void push(int x){
	st[top++] = x;
}

void pop(){
	top--;
}

int main(){
	
	return 0;
}
