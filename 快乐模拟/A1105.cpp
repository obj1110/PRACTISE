#include<iostream> 
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath> 
using namespace std;

//m是行数，n是列数，m行要大于n列，而且取m-n最小的值 
 
int n,temp;
int d[maxn];
int mat[maxn][maxn];

bool cmp(int a,int b){
	return a>b;
}
bool isPrime(int s) {
	if(s ==1) return false;
	int x = sqrt(s);
	for( int x=2 ; x<sqrt(s) ; x++ ){
		if(s%x ==0){
			return false;	
		}
	} 
	return true;
}

void init(){
	scanf("%d",&n);
	temp = 0;
	for(int i=0;i<n;i++){
		scanf("%d",&d[temp++]);
	}
	sort(d,d+n,cmp);
}


int main(){
	init();
	if(n==1){
		printf("%d",A[0]);
	} 
}
