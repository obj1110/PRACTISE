#include<iostream> 

using namespace std;
const int maxn = 1000100;
int array[maxn];

void merge(int A[],int l1,int r1,int l2,int r2){
	int i = l1;
	int j = l2;
	int temp[maxn],index= 0;
	while(i<=R1 && j<=R1){
		if(A[i] <= A[j]){
			temp[index++] = A[i++];
		}
		else{
			temp[index++] = A[j++];
		}
		while(i <= R1)	temp[index++] = A[i++];
		while(j <= R2)  temp[index++] = A[j++];
		for(i=0;i< index;i++){
			A[l1+i] = temp[i];
		}
	}
}
void mergeSort(int A[],int left,int right) {
	if(left<right){
		int mid = (left+ right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid+1,right);
		merge(A,left,mid,,mid+1,right);
	}
}
int main(){
	return 0;
}

