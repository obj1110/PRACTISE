#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 100100;
int array[maxn]= {4,10,11,30,69,70,96,110};
int main(){
	//�������Ҫ����3��λ��: 
	//lower_bound���صĽ���ǵ�һ��>= keyֵ��λ�á� 
	//upper_bound���ص��ǵ�һ��<keyֵ��λ�� 
	//�����ܵĴ�С 
	cout<<sizeof(array)/sizeof(array[0])<<endl;
	//����3�ľ���λ�� 
	int pos1 = lower_bound(array , array+8 , 8) - array;
	int pos2 = upper_bound(array, array+8 , 8) - array;
	cout<<"pos1:"<<pos1<<" "<<"pos2:"<<pos2; 
	return 0;
}
