#include<iostream> 
#include<cstring>
#include<algorithm>
#include<cmath> 
#include<cstdlib>

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
	return b == 0 ? abs(a) :gcd( b , a % b );
}

int main(){
	ll a,b,n,gcdvalue,sa,sb;
	scanf("%lld",&n);
	scanf("%lld/%lld",&sa,&sb);
	
	for(int i=1;i<n;i++){
		scanf("%lld/%lld",&a,&b);
		gcdvalue = __gcd(a,b);
		a /= gcdvalue;
		b /= gcdvalue;
		a *= sb;
		sa *= b;
		sb *= b;
		sa += a;
		gcdvalue = __gcd(sa,sb);
		sa /= gcdvalue;
		sb /= gcdvalue;
	}
	
	ll integer = sa/sb;
	if(integer<0){
		sa += sb*integer;
		sa = abs(sa);
	}
	else{
		sa -= sb*integer;	
	}
	
	
	if(integer==0 && sa==0){
		printf("0");
		return 0;
	}
	
	if(integer==0 && sa!=0){
		printf("%lld/%lld",sa,sb);
		return 0;
	}
	
	if(integer!=0 && sa==0){
		printf("%lld",integer);
		return 0;
	}
	
	if(integer !=0 && sa!=0){
		printf("%lld %lld/%lld",integer,sa,sb);
		return 0;
	}
	
	return 0;
}
