#include<iostream>
using namespace std;

const int maxsize = 100500;
int arr1[maxsize];

void swap(int &array[],int i,int j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int locateZero(int array[]){
	for(int i=0;i<(sizeof(array)/sizeof(array[0]));i++){
		if(array[i] == 0){
			return i; 
		} 
	}
	//��λ 
}

int main(){
	long long cts = 0;
	int n;
	scanf("%d",&n);
	for(int i =0; i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	int index = -1;
	for(int i=0;i<n;i++){
		if(arr[i] == 0){
			index = i;
			break;
		}
	}
	//��ʾ������Ȼ������� 
	int flag = false;
	while(!flag){
		if(arr[index] != index){
			//��Ҫ����
			int temp=-1;
			for(int i=0;i<n;i++) {
				if(arr[temp])
			}
		} 
	}
	return 0;
}
