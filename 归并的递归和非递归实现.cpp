#include<iostream> 
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

const int size = 1000100;

int merge(int a[],int b[],int c[],int n ,int m){
	int i = 0;
	int j = 0;
	int index = 0;
	while (i<n && j<m){
		if(a[i] < b[j]){
			c[index++] = a[i++];
		}
		else {
			c[index++] = b[j++];
		}
	}
	while(i<n) c[index++] =  a[i++];
	while(j<m) c[index++] =  b[j++];
	return index;
} 

const int maxn = 110;
//此处的l2就是r1+1 
void merge_guibing(int a[],int l1,int r1,int l2,int r2){
	int i = l1;
	int j = l2;
	int temp[maxn],index = 0;
	while(i <= r1 && j <= r2){
		if(a[i] < a[j]) temp[index++] = a[i++];
		else temp[index++] = a[j++];
	}
	while(i <= r1 ) temp[index++] = a[i++];
	while(j <= r2 ) temp[index++] = a[j++];
	for(int x=  0;x<index;x++) {
		a[l1+x] = temp[x++];
 	}
}
void mergeSort(int a[],int left, int right){
	if(left<right){
		int mid = left + (right-left)/2;
		mergeSort(a,left,mid);
		mergeSort(a,mid+1,right);
		merge_guibing(a , left , mid , mid+1 , right);
	}
}

int main(){
	int a[] = {9,4,3,6,2,8,1,0,7,5};
	mergeSort(a,0,10);
	vector<int> ve (begin(a),end(a));
	vector<int>::iterator ite;
	for(ite = ve.begin();ite!=ve.end();ite++){
		cout<<*ite<<" ";
	} 
	cout<<endl;
}
