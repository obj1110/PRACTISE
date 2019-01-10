#include<iostream>
#include<vector> 
using namespace std;
//ȫ�����Ǵ�С���������� 
//int swap(int *a,int *b){
//	int x;
//	int *temp = &x;
//	*temp = *a;
//	*a = *b ;
//	*b =*temp;
//} //Ҳ�� 
int swap(int *a,int *b){
	int temp = *a;
	*b = *a;
	*a = temp;
}
int swap(int array[],int left,int right){
	int temp = array[left];
	array[left] = array[right];
	array[right] = temp;
}
int swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}
void insertSort(int num[],int n) {
	for(int i=1;i<n;i++){
		int ans = num[i];
		for(int j=i-1;j>=0;j--){
			if(num[j] < num[j+1]){
			 	int temp = num[j+1];
			 	num[j+1] = num[j];
			 	num[j] = temp;
			}
			else {
				num[j] = ans;
				break;
			}
		}
	}
}

void  fastSort(int num[],int left,int right){
	if(num==NULL) return;
	if(left > right) return;
	int i = left;
	int j = right;
	int temp = num[i];//���� 
	while(i<j){
		while(i<j && num[j]>=temp) j--;
		num[i] = num[j];
		while(i<j && num[i]<= temp) i++;
		num[j] = num[i];
		//������ 
		num[i] = temp; 
	}
	//�����ص�ʱ��Ӧ�þ���i == j��ʱ����
	fastSort(num,left,i-1);
	fastSort(num,i+1,right);
}

int main(){
	int array[10]={2,4,6,8,10,1,3,5,7,9};
	insertSort(array,10);
//	fastSort(array,0,9);
	for(int i=0;i<10;i++){
		printf("%d",*(array+i));
		if(i!=9) printf("\n");
	}
	
//	vector<int> index(array,array+10);
//	vector<int>::iterator ite ;
//	for(ite = index.begin();ite!= index.end();ite++){
//		cout<<*ite<<endl;
//	}
	return 0;
}

