//������ǵ��͵����������ַ���������ַ������м����Ҫ���г���Ϊ���ֵ���
//���Ա�����þ��ǽ���map ���Ҳ�ֹһ�� 

#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;
const int maxn = 10010;
int n,k;

string v[maxn];

bool isPrime(int number){
	if(number==1) return false;
	int sqrt_number = sqrt(number);
	for(int i=2 ; i <= sqrt_number ; i++){
		if(number % i == 0 ) return false;
	}
	return true;
}

map<string,int> str2int;
map<int,string> int2str;
map<string,bool> champion;
map<string,bool> chocolate;
map<string,bool> minion;
map<string,bool> checked;

int main(){
	string str;
	scanf("%d",&n);
	for(int order = 1 ; order <=n; order++){
		cin >> str;
		int2str[order] = str;
		str2int[str] = order;
		if(order== 1 ) champion[str] = true;
		else if(isPrime(order)) minion[str] = true;
		else chocolate[str] =true;
		
		checked[str] = false; 
	}
	// 
	
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		//ע�����string�����ǰ���cin������ 
		cin >> str;
		//map���Ϊ0��ʾ��������һ�Լ�ֵ�Թ�ϵ 
		if(str2int[str] == 0) {
			cout<<str<<": Are you kidding?"<<endl;
			continue;
		}
		else if(checked[str] == true){
			cout<<str<<": Checked"<<endl;
			continue;
		}
		else if(champion[str] ==  true){
			cout<<str<<": Mystery Award"<<endl;
			checked[str] = true;
			continue;
		}
		else if(chocolate[str] == true){
			cout<<str<<": Chocolate"<<endl;
			checked[str] = true; 
			continue;
		}
		else if(minion[str]== true){
			cout<<str<<": Minion"<<endl;
			checked[str] = true;
			continue;
		}
	}
	return 0;
}
