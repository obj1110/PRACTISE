#include<iostream>
using namespace std;

void swap(int *a,int *b){
	int x;
	int *p = &x;//ȷ��ָ��Ĳ���ϵͳ������ 
	*p = *a;  //*a����a��ֵ����ֵ��*p�ǶԵģ�pָ�����a���� 
	*a = *b;
	*b = *p;
}

void swap2(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}
void swap3(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*a =temp; 
}
int main(){
//	int a =10;
//	int *p;
//	p = &a;
//	cout<<"&a:"<<&a<<endl;//pָ��ָ��ĵ�ַ 
//	cout<<"P:"<<p<<endl;  //pָ���ֵ����ַ�� 
//	cout<<"*p:"<<*p<<endl;//pָ��ָ��ĵ�ַ��ֵ 
//	cout<<"&p:"<<&p<<endl;//pָ��ĵ�ַ ��ָ���ָ�룩 
	
//	int b = 10;
//	int c = 20; 
//	swap(b,  c);
//	cout<<b<<" "<<c<<endl;
	
//	int c =20;
//	int x =10;
//	int *a =&x;
//	int *p= &c;
//	*p = *a;
//	cout<<*a<<endl;
//	cout<<*p<<endl;

	int	a =10;
	int b =20;
	swap3(&a,&b);
	cout<<a<<" " <<b<<endl;
}




