#include<iostream>
#include<vector> 
#include<cstring>
#include<string>
#include<stack>

using namespace std;

// 赋初值是空的指针 
int top = -1;

// 清空栈内元素 
void clear(){
	top = -1;
}

// 获取栈内的元素的个数
int size() {
	return top+1;
}

//判断是不是空的 
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
