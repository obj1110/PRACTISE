//��β���룬���׳�ȥ��������ʵ�ֵķ�ʽ����Ϊint��������ʵ�ֵķ�ʽ����Ϊ*int;
//frontָ�����Ԫ�ص�ǰһ��λ�ã�rearָ����Ƕ�β��Ԫ��
//����ֻҪ���ǿյģ�fornt��rear�Ϳ϶��ǲ���� 
//ѭ�����У��жϿպ��ж���������֮��Ĳ�� 

//rear�����һ������е�Ԫ��
//front��������ӵ�Ԫ�ص�ǰһ��Ԫ�� 
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
//rearָ��������һ��Ԫ�أ���������Ҫ�ӣ�Ȼ�����Ԫ�صĸ�ֵ���� 
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
