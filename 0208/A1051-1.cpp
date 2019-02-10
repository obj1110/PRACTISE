//
//Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.
//
//Input Specification:
//Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.
//
//Output Specification:
//For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.


#include<iostream>
#include<stack>
#include<queue>

using namespace std;

//˼·�������е������ģ�������Ȼ�������һ�ĶԱ�
//˼·��������������ָ�룬�ֱ�ָ��ͬ���������飬
//1 �����ǰ��ջ��Ԫ�ظ���վ���е�Ԫ����ͬ������г�վ
//2 �����ǰջ��Ԫ�غ� ��վ���е�Ԫ�ز�ͬ�����ջ 
//3 ���ջ���ǿյģ��ǿ϶���ֱ����ջ

//������ο���ջ��������������أ� 
//���ջ��Ԫ�غͳ�ջ���е�Ԫ�ز�ͬ������ջ�Ѿ����ˣ��Ǿ���һ��ʧ�ܵĳ�ջ���� 


 
int main() {
	//m��ջ�����������n��Ԫ�ص���Ŀ��k��Ҫ����pop���еĳ���
	//Ҳ���Ǹ���һ��ջ�����pop���еĿ����� 
	int m,n,k;
	scanf("%d %d %d",&m,&n,&k);
	
		
	for(int temp_i =0;temp_i<k;temp_i++) {
		queue<int> p;
		queue<int> q;
		stack<int> st;
		for(int i=1 ; i<=n ; i++) {
			p.push(i);
		}
		//����query 
		for(int temp_j = 0 ; temp_j<n ; temp_j++) {
			int temp;
			scanf("%d",&temp);
			q.push(temp);
		}
		//
		int st_size = 0; 
		int p_size = n;
		int q_size = n;
		//
		bool flag = true;
		

		//
		while(flag){
			//
			if(st_size > m){
				flag = false;
				break;
			}
			if(p_size==0 && q_size ==0 && st_size ==0){
				break;
			}
			//
			if(p_size ==0 && st_size != 0  && q_size !=0){
				if(st.top() == q.front()){
					if(st_size > 0) {
						st_size--; 
						st.pop();
					} 
					if(q_size > 0){
						q_size--;
						q.pop();
					}
				}
				else if(st.top() != q.front()){
					flag = false;
					break;
				}
			}
			else if(p_size != 0 && st_size == 0  && q_size !=0){
				if(p.front() == q.front()){
					if(p_size > 0){
						p.pop();
						p_size--;
					}
					if(q_size > 0 ){
						q.pop();
						q_size--;
					}
				}
				else if(p.front() != q.front()){
					st.push(p.front());
					st_size++;
					if(p_size > 0) {
						p.pop();
						p_size--;
					}
				}
			}
			else if(p_size != 0 && st_size != 0  && q_size !=0){
				if(p.front() == q.front()){
					if(p_size > 0){
						p.pop();
						p_size--;
					}
					if(q_size > 0){
						q.pop();
						q_size--;
					}
				}
				else if(st.top() == q.front()){
					if(st_size > 0){
						st.pop();
						st_size--;
					}
					if(q_size > 0){
						q.pop();
						q_size--;
					}
				} 
				else{
					st.push(p.front());
					st_size++;
					if(p_size > 0) {
						p.pop();
						p_size--;
					}
				}
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
