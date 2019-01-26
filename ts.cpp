#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int a = 7601680;
	int b = 7601688;
	cout<<__gcd(a,b);
	a/=8;
	b/=8;
	cout<<a<<" "<<b;
	return 0;	
}
