#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main(){
	map<char,int> mp;
	mp['c'] = 20 ;
	mp['d'] = 21 ; 
	mp['e'] = 22 ;
	mp['f'] = 23 ;
	mp['g'] = 24 ;
	cout << mp['c']<<endl;
	cout<<"key-value pair°üÀ¨:"<<endl;
	cout<<"key | value"<<endl;
	for(map<char,int>::iterator it = mp.begin();it!=mp.end();it++){
		cout<<it->first<<"   |  "<<it->second<<endl;
	}
	
	
	return 0;
}
