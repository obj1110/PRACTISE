//队尾进入，队首出去，用数组实现的方式声明为int，用链表实现的方式声明为*int;
//front指向队首元素的前一个位置，rear指向的是队尾的元素
//所以只要不是空的，fornt和rear就肯定是不相等 
//循环队列，判断空和判断满的条件之间的差别。 

//rear是最近一个入队列的元素
//front是最早入队的元素的前一个元素 
#include<iostream> 
#include<vector>
#include<queue>
using namespace std;

void clear() {
	front = rear = -1;
}
int size(){
	return rear -front;
}
bool empty(){
	if(front == rear) return true;
}
//rear指向的是最后一个元素，所以首先要加，然后才是元素的赋值操作 
void push(int x){
	q[++rear] = x;
}
void pop(int x){
	front++;
}
int get_front() {
	return q[front+1];
}
int get_rear(){
	return q[rear];
}

int main(){
	while(!queue.empty()) {
		int x = queue.get_front();
		queue.pop();
	}
	return 0;
}
