#include <iostream>
using namespace std;

bool isPrime(int n){
	if(n<=1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++) if( n%i==0 ) return false; 
	return true;
}

bool isPrime(int n){
	if(n==1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i=0;i<=sqr;i++){
		if(n%i==0) return false;
	}
	return true;
}

int main(){
	
	return 0;
}
