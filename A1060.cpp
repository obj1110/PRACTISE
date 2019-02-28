//两部分分别获取并且进行比较
//考虑恶意输入情况，包括小数点前全是0和小数点之后也有0的情况 
//情况1： 00000012.12312
//情况2： 123.2314 

//确定第一个非零位的位置
//考虑跟小数点之间的距离，并确定指数 

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int n; //机器的有效位数

string deal(string s,int &e) {
	int k =0 ;
	while(s.length() > 0 && s[0] == '0'){
		s.erase(s.begin());
	}
	//小于1或者是大于1，小于1的情况，指数是负数，大于1的情况，指数是正数 
	if(s[0] =='.'){
		s.erase(s.begin());
		while(s.length()>0 && s[0] =='0'){
			s.erase(s.begin());
			e--;
		}
	}
	else{
		while( k<s.length() && s[k] != '.'){
			k++;
			e++;
		}
		if(k < s.length()){
			//删除小数点 
			s.erase(s.begin() + k );
		}
	} 
	
	//特情 
	if(s.length()==0) {
		e = 0; 
	}
	int  num =0 ;
	k = 0;
	string res;
	while(num < n) {
		if( k < s.length()){
			res += s[k++];
		}
		else{
			res += '0';
		}
		num++;
	}
	return res;
}

int main(){
	//s1 s2 是原始的情况，s3 s4 是后续的情况 
	string s1,s2,s3,s4;
	int e1 = 0;
	int e2 = 0;
	cin>>n>>s1>>s2;
	// 
	s3 = deal(s1,e1);
	s4 = deal(s2,e2);
	if(s3 == s4 && e1 ==e2) {
		cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;
	}
	else{
		cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
	}
	return 0;
}
