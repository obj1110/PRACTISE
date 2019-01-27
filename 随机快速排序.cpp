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
 
int partition(int a[],int left,int right) {
	srand((int)time(NULL));
	//相当于是进行一个归一化操作 
	int p = ( round ( 1.0 * rand() / RAND_MAX * (right -left) + left) );
	swap(a[p],a[left]); 
	
	//
	int temp =a[left];
	int l = left;
	int r = right;
	while( l<r ) {
		while(l<r && a[r]> temp) r--;
		a[l++] = a[r];
		while(l<r && a[l]< temp) l++;
		a[r--] = a[l];
	}
	a[l] = temp;
	return l;
}

using namespace std;
int main(){
	srand((int)time(NULL));
	
	return 0;
}
