#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
int main(){
	string str = "abcd";
	string::iterator it = str.begin();
	for(;it!=str.end();it++){
		cout<<*it<<endl;
	}
	return 0;
}
