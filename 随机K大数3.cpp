#include <iostream> 
#include <cmath> 
#include <time> 
#include <cstring>
#include <utility> 

using namespace std;
const int maxn =1001000;
int a[maxn],n;

int rand_partition(int a[],int left,int right){
	srand((int)time(NULL));
	int p =  round* ( 1.0 * rand()/RAND_MAX * ( right - left ) + left );
	//
	swap(a[p],a[left]);
	//
	int i = left;
	int j = right;
	int temp = a[i];
	//
	while( i < j ){
		while( i < j && a[j] > temp) j--;
		a[i++] = a[j];
		while(i< j && a[i] < temp) i++;
		a[j--] = a[i] ;
	} 
	a[i] = temp;
	return i;
}

void randSelect(int a[],int left,int right,int k){
	if(left== right) return;
	//不是退出程序，而是返回上一层递归 
	
	int p = rand_partition(a,left,right);
	
	int m = p - left + 1;
	
	if( k==m ) return;
	
	if( k<m )  return{
		randSelect(a,left,p-1,k);
	} 
	else {
		return randSelect(a,p+1,k-m);
	} 
}

int main(){
	srand((unsigned)time(NULL));
	int sum =0;
	int sum1 =0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	
	randSelect(a,0,n-1,n/2);
	for(int i=0 ; i < n/2 ; i++){
		sum1 += A[i];
	}
	
	printf("%d\n",(sum -sum1) - sum1);
	return 0; 
} 
