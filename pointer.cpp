#include<iostream>
using namespace std;

void swap(int *a,int *b){
	int x;
	int *p = &x;//确保指向的不是系统变量区 
	*p = *a;  //*a代表a的值，赋值给*p是对的，p指向的是a变量 
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
//	cout<<"&a:"<<&a<<endl;//p指针指向的地址 
//	cout<<"P:"<<p<<endl;  //p指针的值（地址） 
//	cout<<"*p:"<<*p<<endl;//p指针指向的地址的值 
//	cout<<"&p:"<<&p<<endl;//p指针的地址 （指针的指针） 
	
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




