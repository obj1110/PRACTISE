#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;
//也就是说你分配的空间原则要比字符串的字符数目多一个，目的是为了让你的字符串结尾的\0有地方来存放 
int main(){
	string str = "0123456789";
	char str1[11] = "0123456789";
	char str_use[11];
	
	strcpy(str_use,str1);
	cout << str_use;
	return 0;
}
