#include<iostream>
#include<cmath>
#include<cstdlib> 
#include<cstring>
using namespace std;
int main(){
//	abs  // abs
//	fabs // float abs
//	sqrt//
//	pow///
//	
//	ceil// 
//	double ceil(double x);
//	float ceil(float x);
//	long double(long double x);
//	
//	floor//
//	
//	printf ( "ceil of 2.3 is %.1f\n", ceil(2.3) );
//  	printf ( "ceil of 3.8 is %.1f\n", ceil(3.8) );
//  	printf ( "ceil of -2.3 is %.1f\n", ceil(-2.3) );
//  	printf ( "ceil of -3.8 is %.1f\n", ceil(-3.8) );
  	
//  	modf// ���������ֺ�С�����ַֿ������о� ������ص���long double
	long double intpart;
  	long double param = 3.14159265;
  	long double fractpart = modf (param , &intpart);
  	printf ("%llf = %llf + %llf \n", param, intpart, fractpart);
}
//ceil floor �� round����������������Ķ��� 
