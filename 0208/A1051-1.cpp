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

//思路：把所有的情况都模拟出来，然后进行逐一的对比
//思路：创建两个工作指针，分别指向不同的两个数组，
//1 如果当前的栈顶元素跟出站队列的元素相同，则进行出站
//2 如果当前栈顶元素和 出站队列的元素不同，则进栈 
//3 如果栈还是空的，那肯定是直接入栈

//但是如何考虑栈最大容量的作用呢？ 
//如果栈顶元素和出栈队列的元素不同，并且栈已经满了，那就是一个失败的出栈队列 


 
int main() {
	//m是栈的最大容量，n是元素的数目，k是要检查的pop队列的长度
	//也就是根据一个栈，检查pop队列的可行性 
	int m,n,k;
	scanf("%d %d %d",&m,&n,&k);
	
		
	for(int temp_i =0;temp_i<k;temp_i++) {
		queue<int> p;
		queue<int> q;
		stack<int> st;
		for(int i=1 ; i<=n ; i++) {
			p.push(i);
		}
		//读入query 
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
