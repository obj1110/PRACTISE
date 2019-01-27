#include<iostream>
#include<algorithm> 
#include<cstring>
#include<cmath>
#include<time.h>
#include<utility>

using namespace std;

//��߶���pС���ұ߶���p�� 
int randPartition(int A[],int left,int right){
	int p = round(1.0*rand()/RAND_MAX *(right-left)+left);
	swap(A[p],A[left]);
	int temp = A[left];
	while(left<right) {
		while(left < right && A[right] > temp) right--;
		A[left] = A[right];
		while(left < right && A[left] <= temp) left++;
		A[right] = A[left] ;
	}
	A[left] = temp;
	return left;
}

int randSelect(int A[],int left,int right,int k){
	if(left == right ) return A[left];
	int p = randPartition(A,left,right);
	//��������Ԫ����ν�����������Ǽ���������
	//���ǹ��ĵ�����ߵ�Ԫ�ظ���--m 
	int m = p - left + 1;	 
	if(k==m) return a[p];
	if(k > m) return randSelect(A,left,p-1,k); 
	else return randSelect(A,p+1,right,k-m);
}

int main(){
	return 0;	
}
