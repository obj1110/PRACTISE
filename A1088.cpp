#include<iostream>
#include<cstring> 
#include<algorithm>

using namespace std;

int main(){
	int a1,b1,a2,b2,gcd;
	scanf("%d/%d",&a1,&b1);
	scanf("%d/%d",&a2,&b2);
	
	
	//���Ƚ��м򻯣�Ȼ��ֱ����Ӽ�������û����һ������ͽ��л������� 
	a1 *= b2;
	a2 *= b1;
	// 
	a1 += a2;
	b1 *= b2; 
	//
	gcd = __gcd(a1,b1);
	a1 /= gcd;
	b1 /= gcd;
	//����Ĳ��ֲ�Ҫ���Ƕ��ڸ��ţ�����һ��Ҫ�������ţ������������������ֳ��� 
	printf("%d/%d + ");
	
	return 0;
}
