#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int a[100000],b[100000],v[100000];
int n , max = 0;
int cnt = 0;

void init() {
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	sort(a,a+n);
}

int main(){
	init();
	for(int i = 0 ; i<n ; i++){
		//对每一个元素进行遍历 
		if(a[i] == b[i] && b[i] > max ) {
			//将b元素赋值给v 
			v[cnt++] = b[i];
		}
		if(b[i] > max){
			max = b[i] ;
		} 
	}
	
	printf("%d\n",cnt);
	for(int i = 0; i < cnt ;i++){
		if(i !=  0) printf(" ");
		printf("%d",v[i]);
	}
	printf("\n");
	return 0;
}
