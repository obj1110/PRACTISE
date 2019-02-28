//���ȱ��ⲻ�Ƕ���������һ������� 
//1090 ����Ҫʹ��ʲôstruct������������Ҫʹ�ýṹ�壬����˵�����������ʲô�����ϵĲ�𣬶���˵��������Ľڵ㲻ͬ
//1090�Ľڵ�û���κεĸ�����Ϣ����1079�Ľڵ�����Ŵ����ĸ�����Ϣ 

//1094����Ѱ�ҽڵ���������ȣ�Ҳ���Ǳ���ÿһ����Σ��Բ�ͬ�Ľڵ㸳ֵ��ͬ����ȣ�һ�������ʵʱ������ȣ���һ���棬Ҳ��ȫ��������֮�����д���


//1094������Ƚڵ����ļ��䣬����ʹ��int���鹹���hashTable֮�⣬������ʹ��map 
#include<iostream> 
#include<vector>
#include<map> 

using namespace std;

const int maxn = 110;

//���ľ�̬д����������
//���Ķ�̬д�������������ָ�� 
vector<int> Node[maxn] ;
int hashTable[maxn] = {0};

void DFS(int index,int depth){
	hashTable[depth]++;
	//ͳ��ÿһ���ڵ���ӽڵ㣬��Ϊ�������Ƕ����������������� 
	for(int j =0;j < Node[index].size();j++){
		DFS(Node[index][j],depth+1);
	}
}

//int father,root;
//
//double p,r,ans;//p�Ǽ۸�r��ratio����,ans���ܼ�ֵ 
//
//// ȫ�ֱ��������ڼ��������� 
////numf���������ȵĽڵ����  
//int n,maxDepth,num,k,child; 
//
//
////�������ľ�̬����洢��ʽ����ʽ��ž���һ����ά���飬��һ��ά�ȴ���ڵ�
////�ڶ���ά�ȴ�������ڵ���ӽڵ����� 
//void DFS(int index,int depth){
//	//�����Ҷ�ڵ� 
//	if(Node[index].child.size() == 0 ) {
//		ans += Node[index].data * pow(1+r,depth);
//		//һ�������ӽڵ��Ҫ������ 
//		return ;
//	} 
//	//�������Ҷ�ڵ� 
//	else if( Node[index].child.size() != 0 ) {
//		for(int i = 0;i < Node[index].child.size();i++) {
//			DFS(Node[index].child[i],depth+1);
//		}
//	}
//}


//����Ĳ���
//0�Žڵ�̶���root
//���ȸ����ӽڵ�ĸ���������ӽڵ�ĸ�����0 ����ô��������־����ӽڵ�Ļ�����
//����ӽڵ�ĸ�������0, �Ǻ���Ķ��������ӽڵ��id�ţ�����Щid�ŷ��ڶ�ά����ĵڶ���ά����
//�������ľ�̬����
 


int main(){
	
	int n,m,parent,k,child;
	scanf("%d%d",&n,&m);
	for(int i =0 ;i<m;i++){
		scanf("%d %d",&parent,&k);
		for(int j = 0; j<k;j++){
			scanf("%d",&child);
			Node[parent].push_back(child);
		}
	}
	//����ĳ�ʼ�ڵ���1����ʼ���0����1������ 
	DFS(1,1);//0�Žڵ㣬�����0
	int maxLevel = -1;
	int maxValue = 0;
	for(int i=0;i<maxn;i++) {
		if(hashTable[i] > maxValue){
			maxValue = hashTable[i];
			maxLevel = i;
		}
	}
	printf("%d %d\n",maxValue,maxLevel);
	return 0;
}
