//��ʼ������������
//��ͷ�ڵ㿪ʼ���������ҳ�������Ч�ڵ㲢��ǣ�
//��Ч�ڵ㰴�շ�ת����������±�ţ�
//��������
//������Ŀ��ʽҪ�����������ֵ��


//Ҫ���������������
	//���������ýڵ�
	//���������ýڵ� ��Ҳ����ͷ���ָ���Ԫ�ز����ڣ�����˵��ͷ���ָ���Ԫ���Ǵ���Ĳ����ڵ�Ԫ�أ���������£�������ʣ���Ԫ����һ������ 
	//���ýڵ�ֻ��1����ʣ��ȫ����Ԫ�ض������ýڵ����� 



#include<iostream>
#include<algorithm>
#include<cmath> 
#include<cstring>

using namespace std;

const int maxn =  1000100;

struct Node{
	int add;
	int data;
	int next;
	int flag;
}node[maxn],node1[maxn]; 
//node���õ�����
//node1��û���õ����Ľڵ� 

int hash_map[10010];

//����node�������� 
bool cmp(Node a,Node b){
	if(a.flag != b.flag) return a.flag > b.flag;
	else return abs(a.data) > abs(b.data);
}
//����node1�������� 
bool cmp1(Node a,Node b){
	if(a.flag != b.flag) return a.flag > b.flag;
}


int main(){
	//��ʼ�� 
//	memset(hash_map,0,10010);
	int h1,h2,n,cts=0;
	int cts1 = 0;
	int a,b,c;
	//���ݵ����� 
	scanf("%d %d",&h1,&n);
	while(n--) {
		scanf("%d %d %d",&a,&b,&c);
		node[a].add = a;
		node[a].data = b;
		node[a].next = c;
		//��� 
		hash_map[abs(b)] = 1;
	}

	//����Ч�ڵ����Ч�ڵ�ֿ������Ҷ���Ч�ڵ�������� 
	while(h1!= -1){
		cts++;
		node[h1].flag = 1;
		h1 = node[h1].next;
	}
	sort(node,node+maxn,cmp);
	//

	//special ��������0 
//	if(cts==0){
//		printf("00000 0 -1\n");
//		return 0;
//	}
		
	//
	h1 = node[0].add;	
	int temp_cts_1 = cts;
	int temp_cts_2 = 0;
	int index = 0;
	
	for(int i=0 ; i < cts ; i++){
		int data = abs(node[i].data);
		if(hash_map[data] == 1){
			hash_map[data] = 0;
		}
		else{
			node1[index] = node[i];
			index++;
			node[i].flag = -1;
			temp_cts_1--;
			temp_cts_2++;
		}
	}
	cts = temp_cts_1;
	cts1 = temp_cts_2;
	//
//	cout<<"cts: " <<cts<<endl;
//	cout<<"cts1: "<<cts1<<endl;
	//
	sort(node,node+maxn,cmp);
	sort(node1,node1+maxn,cmp1);
	


	// ���½�����ϵ 
	h1 = node[0].add;
	for(int i=0;i<cts-1;i++) {
		node[i].next = node[i+1].add;
	}
	node[cts-1].next = -1;
	//
	// ���½�����ϵ 
	h2 = node1[0].add;
	for(int i=0;i<cts1-1;i++) {
		node1[i].next = node1[i+1].add;
	}
	node1[cts1-1].next = -1;
	
	// ��ӡ 
	if(cts != 0) {
		for(int i=0  ;   i<cts-1  ;  i++){
			printf("%05d %d %05d\n",  node[i].add,   node[i].data,  node[i].next);
		}
		printf("%05d %d -1\n",node[cts-1].add,node[cts-1].data);
	}

	// ��ӡ 
	if(cts1 !=0){
		for(int i=0  ;  i<cts1-1  ;  i++){
			printf("%05d %d %05d\n",  node1[i].add,   node1[i].data,  node1[i].next);
		}
		printf("%05d %d -1\n"  ,   node1[cts1-1].add  ,  node1[cts1-1].data);
	}


	
	return 0;
}
