#include<iostream>
#include<cstring> 
#include<algorithm>

using namespace std;

int main(){
	int a1,b1,a2,b2,gcd;
	scanf("%d/%d",&a1,&b1);
	scanf("%d/%d",&a2,&b2);
	
	
	//首先进行简化，然后分别计算加减乘数，没算完一个结果就进行化简和输出 
	a1 *= b2;
	a2 *= b1;
	// 
	a1 += a2;
	b1 *= b2; 
	//
	gcd = __gcd(a1,b1);
	a1 /= gcd;
	b1 /= gcd;
	//输出的部分不要忘记对于负号，我们一定要加上括号，符号优先在整数部分出现 
	printf("%d/%d + ");
	
	return 0;
}
