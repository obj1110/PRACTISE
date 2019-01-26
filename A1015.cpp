//如果一个数本身是素数，而且在d进制下反转后的数在十进制下也是素数，就输出Yes，否则就输出No
//分析：判断输入是否为负数，判断n是否为素数，把n转换为d进制再反过来转换为10进制，判断是否为素数

//就是一个数，先转换为D进制，然后调换顺序，然后D进制的新数再回到十进制，然后判断这个数是不是素数。
//当然首先判断自己本身是不是素数。
#include<iostream> 
#include<cmath> 
using namespace std;
bool isPrime(int number){
	if(number%2==0){
		return false;
	}
	for(int i=3;i<sqrt(number);){
		if(number%i==0){
			return false;
		}
		i=i+2;
	}
	return true;
}

int main(){
	int N,M,temp=0,result=0;
	while(1){
		scanf("%d",&N);
		if(N<0){
			return 0;	
		}
		scanf("%d",&M);
		if(!isPrime(N)){
			cout<<"No"<<endl;
			continue;
		} 
		// 
		if(N==0){
			cout<<"Yes"<<endl;
		}
		while(N!=0){
			temp = N%M;
			result = result*10 + temp;
			N = N/M; 
		}
		int temp2 = 1;
		temp =0; 
		N=0;
		while(result!=0){
			temp = result%10*temp2;
			result = result/10;
			N = N + temp;
			temp2*=M;
		} 

		if(isPrime(N)){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
		//其实这样做已经是一个反的二进制了，然后把这个二进制变成10进制，判断获取的十进制的结果是不是素数。 
	}
	return 0;
}

