#include<iostream>
#include<cstring> 
#include<vector>
using namespace std;
int main(){
	int array[5] ={-2};
	int array1[5] ={0};
	//���ߵ�Ч����һ���� 
	//��ʼ�� 
	vector<int> index(array,array+sizeof(array)/sizeof(array[0]));
	//������ 
	vector<int>::iterator ite;
	//������� 
	for(ite =index.begin();ite!=index.end();ite++){
		cout<<*ite<<endl;
	}
	cout<<"============="<<endl;
	
	int array2[5];
	cout<<"sizeof(array2):"<<sizeof(array2) <<endl;
//	memset(array2,0,sizeof(array2));
	memset(array2,-1,sizeof(array2));
//	memset(array2,1,sizeof(array2));
	for(int i=0;i<(sizeof(array2)/sizeof(array2[0]));i++){
		cout<<array2[i]<<endl;
	}
	 
}
