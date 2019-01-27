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

//���صĶ��������յ������λ�� 
int partition(int a[],int left,int right){
	//Ĭ�ϵĵ�һ��Ԫ������ߵ�Ԫ�� 
	//ֱ�Ӱ�left��right��ָ�벻��
	int l = left;
	int r = right; 
	int temp = a[l];
	while(l<r){
		while(l<r && a[r]>temp) r--;
		a[l] = a[r];
		while(l<r && a[l]<temp) l++;
		a[r] = a[l];
	}
	a[l] = temp;
	return l;
}

void quickSort(int a[],int left,int right) {
	if(left<right){
		int pos = partition(a,left,right);
		quickSort(a,left,pos-1);
		quickSort(a,pos+1,right);
	}
}

//
int partition(int a[], int left ,int right) {
	int temp = a[pos];
	while(left<right){
		while(left<right && a[right]> temp)   right--;
		a[left] = a[right];
		while(left<right && a[left]<temp) left++;
		a[right] = a[left];
	}
	a[left] = temp;
	return left;
}

void quickSort(int a[],int left,int right){
	if(left<right){
		int pos= partititon(a,left,right);
		quickSort(a,left,pos);
		quickSort(a,pos+1,right);
	}
}

void QuickSort(int a[],int left ,int right){
	int i = left;
	int j = right;
	int temp = a[i];
	
	while(i<j){
		while(i<j && a[j]> temp ) j--;
		if(i<j){
			a[i]  =a[j];
			i++;	
		}
		while(i<j && a[i] <temp ) i++;
		if(i<j){
			a[j] = a[i];
			j--;	
		}
	}
	
	//�������������λ�� 
	a[i] = temp;
	return 0;
}



int main(){
	
}
