#include<iostream>
using namespace std;
const int size = 100000;
//�������е���ֵ��������500��������ʵ��ȫ������hash˼�������� 
bool value[520];

int main(){
	memset{value,false,sizeof(value)};
	
	int n,m,temp;
	
	scanf("%d %d",&n,&m); 
	
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		value[temp] = true;
	}
	for(int i=0;i<=250;i++){
		if(value[i]==true && value[m-i]==true){
			cout<<i<<" "<<m-i<<endl;
			return 0;
		}
	}
	cout<<"No Solution";
	return 0;
}
