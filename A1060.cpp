//�����ֱַ��ȡ���ҽ��бȽ�
//���Ƕ����������������С����ǰȫ��0��С����֮��Ҳ��0����� 
//���1�� 00000012.12312
//���2�� 123.2314 

//ȷ����һ������λ��λ��
//���Ǹ�С����֮��ľ��룬��ȷ��ָ�� 

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int n; //��������Чλ��

string deal(string s,int &e) {
	int k =0 ;
	while(s.length() > 0 && s[0] == '0'){
		s.erase(s.begin());
	}
	//С��1�����Ǵ���1��С��1�������ָ���Ǹ���������1�������ָ�������� 
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
			//ɾ��С���� 
			s.erase(s.begin() + k );
		}
	} 
	
	//���� 
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
	//s1 s2 ��ԭʼ�������s3 s4 �Ǻ�������� 
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
