#include<iostream>
#include<string>
using namespace std;
int main(){
//	×ªÊý×Ö 
	string str = "100";
	int num = stoi(str);
	long int num2 = stol(str);
	long long num1 = stoll(str);
	
	
//	×ªstr 
	string substr = to_string(num);
	return 0;
}
