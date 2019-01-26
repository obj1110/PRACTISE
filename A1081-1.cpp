#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

typedef long long ll;

const int maxn = 1000100;
int array[maxn];

int main(){
	int n;
	long long a,b;
	scanf("%d",&n);
	long long int ans = 0;
	long long int ansb = 1;
	long long int ansa = 0;
	//结果的三个部分
	 
	for(int i=0;i<n;i++){
		scanf("%ld/%ld",&a,&b);
		if(i==0){
			ansa = a;
			ansb = b;
		}
		else{
			long long tempb = b;
			a *= ansb;
			b *= ansb; 
			ansa *= tempb;
			ansb *= tempb;
			ansa+= a;
			//通分之后相加 
		}
		while(ansa%2==0 && ansb%2==0){
			ansa/=2;
			ansb/=2;
		}
		while(ansa%3==0 && ansb%3==0){
			ansa/=3;
			ansb/=3;
		}
		while(ansa%5==0 && ansb%5==0){
			ansa/=5;
			ansb/=5;
		}
		while(ansa%7==0 && ansb%7==0){
			ansa/=7;
			ansb/=7;
		}
	}
	
	if(abs(ansa)>abs(ansb)){
		if(a>0) {
			ans += (a/b);
			a -= (a/b)*b;
		}
		else if(a<0) {
			ans -= (a/b);
			a += (a/b)*b;	
		}	
	}
	if(ansa<0) printf("-");
	printf("%d %d/%d",ans,ansa,ansb);
	return 0;
}
