#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
		string number1;
		string number2;
		int number3;
		
		string s1("ssss");
		string s2(s1);
		string s3 = s2;
		string s4(10,'c');
		string s5 = 'hiya';
		string s6 = string(10,'c');
		
		char cs = "123dcv";
		string s7(cs,3);
		
		string s8  = "qwed";
		string s9(s8,2);
		
		string s10 = "wecwd";
		string s11(s10,2,3);
		

		string s10 = s3.substr();
		 
	return 0;	
}
