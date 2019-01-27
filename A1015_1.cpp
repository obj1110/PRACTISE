//���һ����������������������d�����·�ת�������ʮ������Ҳ�������������Yes����������No
//�������ж������Ƿ�Ϊ�������ж�n�Ƿ�Ϊ��������nת��Ϊd�����ٷ�����ת��Ϊ10���ƣ��ж��Ƿ�Ϊ����

//����һ��������ת��ΪD���ƣ�Ȼ�����˳��Ȼ��D���Ƶ������ٻص�ʮ���ƣ�Ȼ���ж�������ǲ���������
//��Ȼ�����ж��Լ������ǲ���������

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

