#include<cstdio>
#include<iostream>
using namespace std;
const int SIZE =1010;
int main(){
	int index[SIZE] = {0};//emmmmm���ַ���Ҫ���գ����ǰ�һ������ȫ����ʼ��Ϊ0 
	int a,b,cts=0;
	//����ĸ�����Ҫʹ��EOF�����ж�
	//�����ʱ������������߽ף������ʱ������������ͽס��㲻��������Ȼ����Ϊ���е������׵ġ� 
	while(scanf("%d%d",&a,&b)!=EOF){
		index[b] += a;
	}
}
