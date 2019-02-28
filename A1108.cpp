//怎么判断负数，怎么判断小数位数太多的情况modf函数 

#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;
const int maxn = 1050;
const int inf = 0x3fffffff;
int n,cts=0;
char num[100];
vector<double> d;

bool check(char num[]){
	int point_time = 0;
	int xiaoshuweishu = 0;
	for(int i=0;i<strlen(num);i++){
		//处理小数位数 
		if(point_time > 0){
			xiaoshuweishu++;
		}
		//处理负数 
		if(i==0 && num[i] =='-') continue;
		if(num[i] == '.') {
			point_time++;
			continue;	
		}
		//使用isalpha还是使用isdigit呢？？？ 
		else if(!isdigit(num[i])) return false;
	}
	if(point_time >= 2 ) return false;
	if(xiaoshuweishu > 2) return false;
	// 起码确保是数字了  
	double number = stod(num);
	if(fabs(number) > 1000) return false;
	return true;
}

int main(){
	cts = 0;
	scanf("%d",&n);
	//基础还是不扎实，不然这种低级的错误不应出现 
	for(int i=0;i<n;i++){
		cin>>num;
		getchar();
		if(check(num) ==true){
			d.push_back(stod(num));
			cts++;	
		} 
		else{
			printf("ERROR: %s is not a legal number\n",num);
		}
	}
	if(cts==0){
		printf("The average of 0 numbers is Undefined");
		return 0;
	}
	if(cts==1) {
		printf("The average of 1 numbers is %0.2lf",d[0]);
		return 0;
	}
	double value = 0;
	for(auto &x :d){
		value+= x;
	}
	printf("The average of %d numbers is %0.2lf",cts,value/cts);	
	return 0;
}
