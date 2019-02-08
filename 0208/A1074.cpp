//��ʼ������������
//��ͷ�ڵ㿪ʼ���������ҳ�������Ч�ڵ㲢��ǣ�
//��Ч�ڵ㰴�շ�ת����������±�ţ�
//��������
//������Ŀ��ʽҪ�����������ֵ��

#include<iostream>
#include<algorithm>

using namespace std;

const int maxn =  1000100;

struct Node{
	int add;
	int data;
	int next;
	int flag;
}node[maxn]; 

bool cmp(Node a,Node b){
	if(a.flag != b.flag) return a.flag > b.flag;
	else return a.data < b.data;
}

int main(){
	//k��sublist�ĳ���,����Ҫ�ı��� 
	int h1,n,k,cts=0;
	int a,b,c;
	scanf("%d %d %d",&h1,&n,&k);
	while(n--) {
		scanf("%d %d %d",&a,&b,&c);
		node[a].add = a;
		node[a].data = b;
		node[a].next = c;
	}

	//������Ч�ڵ�ĸ��� 
	while(h1 != -1){
		cts++;
		node[h1].flag = 1;
		h1 = node[h1].next;
	}
	
	//special
	if(cts==0){
		printf("00000 0 -1\n");
		return 0;
	}
	//����Ч�ڵ����Ч�ڵ�ֿ������Ҷ���Ч�ڵ�������� 
	sort(node,node+maxn,cmp);
	//

	//����λ�� 
	if(k > cts){
		//continue; 
	}
	//k <= cts ����Ҫ����˳��ı仯 
	else{
		int init =0;
		while(init + k <cts) {
			int i = 0;
			int j = k-1;
			while(i <= j){
				swap(node[i],node[j]) ;
//				swap( node[i].add , node[j].add  );
//				swap( node[i].data, node[j].data );
//				swap( node[i].next, node[j].next );
				i++;
				j--; 
			} 
			init += k;
		}
	}
	// ���½�����ϵ 
	h1 = node[0].add;
	for(int i=0;i<cts-1;i++) {
		node[i].next = node[i+1].add;
	}
	node[cts-1].next = -1;
	// ��ӡ 
	for(int i=0;i<cts-1;i++){
		printf("%05d %d %05d\n",  node[i].add,   node[i].data,  node[i].next);
	}
	printf("%05d %d -1\n",node[cts-1].add,node[cts-1].data);
	return 0;
}
