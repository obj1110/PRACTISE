#include<iostream> 
using namespace std;
int main(){
	char str[10];
	//接受字符串，可以接收空格
	//与.get相比就是无法接收空格 
	cin.getline(str,20,'\0');
	//默认用换行作为结束符号，可以手动更改为其他符号 
	return 0;
}
