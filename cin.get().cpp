#include<iostream> 
using namespace std;
int main(){
	char ch;
	char str[10];
	ch =cin.get(); 
	cin.get(ch); 
	//接收单个字符的两种方式
	
	//接收带有空格的字符串，以换行或长度结束 
	cin.get(str,10); 
	
	return 0;
}
