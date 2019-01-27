//如果一个数本身是素数，而且在d进制下反转后的数在十进制下也是素数，就输出Yes，否则就输出No
//分析：判断输入是否为负数，判断n是否为素数，把n转换为d进制再反过来转换为10进制，判断是否为素数

//就是一个数，先转换为D进制，然后调换顺序，然后D进制的新数再回到十进制，然后判断这个数是不是素数。
//当然首先判断自己本身是不是素数。

#include<iostream> 
#include<cmath> 

using namespace std;

bool isPrime(int n){
	if(n<=1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if( n%i == 0) return false;
	}
	return true;
}

int main(){
	int n;
	int radix;
	while(scanf("%d",&n)!=EOF){
		if(n<0) break;
		scanf("%d",&radix);
		if(isPrime(n) == false) printf("No\n");
		else{
			int value = 0;
			while(n!=0) {
				value = value*radix + n%radix;
				n = n/radix; 
			}
			if(isPrime(value)) printf("Yes\n");
			else printf("No\n");
		}
	} 
	return 0;
}

