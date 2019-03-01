#include<algorithm> 
#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>
using namespace std;

void heap_build(int a[],int root,int length){
	int lchild = root*2+1;
	if(lchild < length){
		//����ѡ������бȽϴ���Ǹ�Ԫ�� 
		int flag = root*2 + 1;
		int rchild = lchild + 1;
		if(rchild < length){
			//Ȼ�����ɸѡ�����бȽϴ���Ǹ�Ԫ�� 
			if(a[rchild] > a[flag]){
				flag = rchild;
			}
		}
		// ������ڵ������ڵ�ҪС���ͽ������ߵ�λ�� 
		if(a[root] < a[flag]){
			swap(a[root],a[flag]);
			Heap_build(a,flag,length);
			//Ȼ��ݹ��һ��·����ȥ���𽥵Ľ�����·���ϵ����е㶼������ 
		}
	}
}

void heap_sort(int a[],int len) {
	//���һ����Ҷ�ӽڵ㿪ʼ�о� 
	for(int i= len/2; i>=0;i--){
		heap_build(a,i,len); 
	}
	//������ϣ���ʼ���� 
	for(int j=len -1;j>0;j--){
		swap(a[0],a[j]); 
		//��������ȥ�ģ�0��Ԫ�ص�λ�� 
		heap_build(a,0,j);
	}
}

int main(){
	
}
