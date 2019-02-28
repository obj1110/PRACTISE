//��ô�жϸ�������ô�ж�С��λ��̫������modf���� 

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
		//����С��λ�� 
		if(point_time > 0){
			xiaoshuweishu++;
		}
		//������ 
		if(i==0 && num[i] =='-') continue;
		if(num[i] == '.') {
			point_time++;
			continue;	
		}
		//ʹ��isalpha����ʹ��isdigit�أ����� 
		else if(!isdigit(num[i])) return false;
	}
	if(point_time >= 2 ) return false;
	if(xiaoshuweishu > 2) return false;
	// ����ȷ����������  
	double number = stod(num);
	if(fabs(number) > 1000) return false;
	return true;
}

int main(){
	cts = 0;
	scanf("%d",&n);
	//�������ǲ���ʵ����Ȼ���ֵͼ��Ĵ���Ӧ���� 
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
