#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 1000100;
int array[maxn]={0};

//��ɵ��������� 
int cmp1(char a,char b){
	return a<=b;
}
//��ɵݼ������� 
int cmp2(char a,char b){
	return a>=b;
} 

//���⣺����0û���κ����  
//���⣺����1�ȸ�λ���������������׼
//����:���벻��4λ����ʱ��������������
 
int main(){
	string number1,number2;
	cin>>number1;
	
	number2 = number1;
	int number3 = stoi(number1);
	
	if(number3 ==0){
		cout<<"0000 - 0000 = 0000"<<endl;
		return 0;
	}
	
	//ǿ����䵽3λ�� 
	if(number3 <1000 && number3 >= 100) number3*=10;
	else if(number3<100 && number3>=10) number3 *=100;
	else if(number3>0 && number3 <=9) number3 *=1000;
	number1 = number2 = to_string(number3);
	
	while(number3 != 6174 && number3!=0){
		sort(number1.begin(),number1.end(),cmp2);
		sort(number2.begin(),number2.end(),cmp1);
		number3 = stoi(number1) - stoi(number2);
		//������� 
		cout<<number1<<" - "<<number2<<" = ";
		printf("%04d",number3);
		//
		if(number3 != 6174 && number3 != 0) printf("\n");
		else return 0;
		
		//int תnumber
		if(number3<1000 && number3>=100) number3 = number3*10;
		else if(number3 >=10 && number3 <100) number3 = number3*100;
		else if(number3 <10) number3 = number3*1000;
		
		//numberתstring 
		number1 = number2 = to_string(number3);
		}	
	return 0;	
}
