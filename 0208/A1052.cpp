#include<iostream> 
#include<algorithm> 
#include<cstdlib>
#include<cstring>

using namespace std;

//����99999 
const int maxn = 100100;
//���ݷ�Χ int ����10�� 
struct Node{
	int data;
	int next;
	int add;
	int flag; //flag==1 ��ʾ������Ч�ڵ�
	//flag==0 ��ʾ������Ч�ڵ� 
}node[maxn];

//Node �ǽṹ������ node �ǽṹ������ 

//cmp�����ã�ɸѡ��Ч�ڵ㣬�����ж��δ��� 
bool cmp(Node a,Node b){
	//������ٴ���һ����Ч�ڵ� 
	if(a.flag != b.flag) return a.flag > b.flag;
	else{
		return a.data < b.data; 
	}
}

int main(){
	int h1,n;
	int a,b,c;
	int cts = 0 ;
	scanf("%d %d",&n,&h1);
	while(n--){
		scanf("%d %d %d",&a,&b,&c);
		node[a].add = a;
		node[a].data = b;
		node[a].next = c;
	}
	//����Ľڵ㲻һ�������������ϵ� 
	//������������flag 
	while(h1 != -1){
		cts++;
		node[h1].flag = 1;
		h1 = node[h1].next;
	}
	sort(node,node+maxn,cmp);
	 
	h1 = node[0].add;
	//special 
	if(cts==0){
		printf("0 -1");
		return 0;
	}
	// 
	printf("%d %05d\n",cts,h1);
	for(int i=0;i<cts;i++){
		printf("%05d %d",node[i].add,node[i].data);
		if(i!= cts-1){
			printf(" %05d\n",node[i+1].add); 
		}
		else{
			printf(" -1\n");
		}
	}
	return 0;
}
