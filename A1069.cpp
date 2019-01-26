#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 1000100;
int array[maxn]={0};

//变成递增的序列 
int cmp1(char a,char b){
	return a<=b;
}
//变成递减的序列 
int cmp2(char a,char b){
	return a>=b;
} 

//问题：输入0没有任何输出  
//问题：输入1等个位数，不符合输出标准
//问题:输入不满4位数的时候，输出是有问题的
 
int main(){
	string number1,number2;
	cin>>number1;
	
	number2 = number1;
	int number3 = stoi(number1);
	
	if(number3 ==0){
		cout<<"0000 - 0000 = 0000"<<endl;
		return 0;
	}
	
	//强行填充到3位数 
	if(number3 <1000 && number3 >= 100) number3*=10;
	else if(number3<100 && number3>=10) number3 *=100;
	else if(number3>0 && number3 <=9) number3 *=1000;
	number1 = number2 = to_string(number3);
	
	while(number3 != 6174 && number3!=0){
		sort(number1.begin(),number1.end(),cmp2);
		sort(number2.begin(),number2.end(),cmp1);
		number3 = stoi(number1) - stoi(number2);
		//输出部分 
		cout<<number1<<" - "<<number2<<" = ";
		printf("%04d",number3);
		//
		if(number3 != 6174 && number3 != 0) printf("\n");
		else return 0;
		
		//int 转number
		if(number3<1000 && number3>=100) number3 = number3*10;
		else if(number3 >=10 && number3 <100) number3 = number3*100;
		else if(number3 <10) number3 = number3*1000;
		
		//number转string 
		number1 = number2 = to_string(number3);
		}	
	return 0;	
}
