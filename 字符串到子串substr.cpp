#include<iostream>
#include<cstring> 
#include<algorithm> 
using namespace std;
int main(){
	char item[10];
	strcpy(item,"-123456789");
	item = item.substr(1,strlen(item)-1);
	cout<<item;
	return 0;
}
