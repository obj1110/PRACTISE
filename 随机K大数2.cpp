#include <iostream> 
#include <cmath> 
#include <time> 
#include <cstring>
#include <utility> 

using namespace std;


void partition(int a[],int left,int right){
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

int randSelect(int a[],int left,int right,int k){
	if(left< right) return a[left];
	int p = randpartition(a,left,right);
	int m = p - left + 1;
	if( k==m ) return a[p];
	if( k<m )  return randSelect(a,left,p-1,k);
	else return randSelect(a,p+1,k-m);
}

int main(){
	return 0; 
} 
