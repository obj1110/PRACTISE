#include<iostream>
#include<cstdlib> 
#include<cmath>
#include<algorithm>
using namespace std;
 
long long gcd(long long a, long long b) {return b == 0 ? abs(a) : gcd(b, a % b);}

int main(){
	int a=10;
	int b=30;
	cout<<__gcd(a,b)<<endl;
	return 0; 
} 

long long gcd(long long a,long long b){return b==0?abs(a):gcd(b,a%b)}

long long gcd(long long a,long long b) {return b==0?abs(a):gcd(b,a%b);}
