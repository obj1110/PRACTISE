//���һ����������������������d�����·�ת�������ʮ������Ҳ�������������Yes����������No
//�������ж������Ƿ�Ϊ�������ж�n�Ƿ�Ϊ��������nת��Ϊd�����ٷ�����ת��Ϊ10���ƣ��ж��Ƿ�Ϊ����

//����һ��������ת��ΪD���ƣ�Ȼ�����˳��Ȼ��D���Ƶ������ٻص�ʮ���ƣ�Ȼ���ж�������ǲ���������
//��Ȼ�����ж��Լ������ǲ���������
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
		//��ʵ�������Ѿ���һ�����Ķ������ˣ�Ȼ�����������Ʊ��10���ƣ��жϻ�ȡ��ʮ���ƵĽ���ǲ��������� 
	}
	return 0;
}

