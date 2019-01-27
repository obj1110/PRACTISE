#include<iostream> 
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<cmath>
#include<time.h>
#include<utility> 

using namespace std;
const int maxn = 1000100;
typedef long long ll;

int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
 
int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

bool isPrime(int n){
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i=2;i<sqr;i++){
		if(n%sqr==0) return false;
	}
	return true;
}

int main(){
	return 0;
}
