//��������þ�̬��������ʱ��һ�������򣬴洢�Ƿ񱻷��ʹ���
//��һ���������ͬʱ�޸ķ���λ��


//�����ڶ�������ʱ�������ʹ������������ҵ�������׺����㣬�絽ĩβҲδ�ҵ�˵��û�й�����׺��


//������������0ֵ��

//���������ǵ�һ�����������ͷ�ڵ� ������
 
 
//�����в��ÿ����κεĸ������йص����ݣ��������ǵ�ַ���� 
 
#include<iostream> 
#include<vector>
const int maxn  = 100010;

using namespace std;

//���еĵ�ַ������99999������������鿪100k���� 
struct Node{
	int next;
	int vis;
}node[maxn];

int main(){
	int h1,h2,h3,n;
	int a,c;
	char b;
	scanf("%d %d %d ",&h1,&h2,&n);
	//�洢���� 
	for(int i=0;i<n;i++){
		scanf("%d %c %d",&a,&b,&c);
		node[a].next = c;
		node[a].vis = 0;
	}
	//�����һ������ʵ���� 
	while(h1 != -1) {
		node[h1].vis = 1;
		h1 = node[h1].next;
	}
	while(h2 != -1){
		if(node[h2].vis != 1 ){
			h2 = node[h2].next;
			continue;
		}
		else{
			break;
		}
	}
	// ����h2��whileѭ��
	if(h2==-1) {
		printf("-1");
	}
	else{
		printf("%05d",h2);
	}
	return 0;
}
