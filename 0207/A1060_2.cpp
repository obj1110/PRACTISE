// 0000.000231
// 0123.000123
// 1234.123434 3
// 1234.123434 7

#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int n;

string deal(string s,int &e){
	int k=0; //k是工作指针 
	int count = 0; //统计一下小数点后面的0的个数 
	while(s.length() > 0 && s[0] =='0'){
		s.erase(s.begin());
	}
	//
	if(s[0]=='.'){
		s.erase(s.begin());
		while(s.length() >0 && s[0]=='0'){
			s.erase(s.begin());
			count--;//小数点后减 
		}
	}
	else{
		while( k < s.length() && s[k] != '.'){
			k++;
			count++;//小数前加 
		}
		if( k< s.length()) {
			s.erase(s.begin()+k);
		}
	}
}

int main() {
	string s1,s2,s3,s4;
	int e1 = 0;
	int e2 = 0;
	cin >> n >> s1 >>s2;
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
