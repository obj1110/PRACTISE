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
//�˴���l2����r1+1 
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

//step������left ��right�ľ���
//step/2������һ���������ڵ�Ԫ�ص���Ŀ 
//step����������Ĵ�С��step/2��������һ������Ĵ�С 
void merge_nonrecursion (int a[]){
	//һ��ʼ��ÿ����Ԫ�ؽ���һ���鲢 
	for(int step =2;step/2<=n;step*= 2){
		for(int left=1;left<=n;left+=step){
			int mid = left + step/2 -1; 
			if(mid+1<=n) {
				merge(a,left,mid,mid+1,min(left + step -1,n));
			}
		}
	}
}

void mergeSort_sort(int a[]){
	for(int step =2;step/2<=n;step*=2){
		for(int i=0;i<=n;i+=step){
			sort(a+i,a+min(i+step,n+1));
		} 
		//��ӡ��ǰ������һ������
		vector<int> ve(begin(a),end(a));
		for(auto c:ve){
			cout<<c;
		}
	} 
} 


void mergeSort(int a[]){
	for(int step=2 ; step/2<=n ; step*=2) {
		for(int i=0;i<=n;i+=step){
			//��Ϊ���sort������ҿ���  
			sort(a+i,a+min(i+step,n+1)); 
			//�������ԭ����merge����
			int mid = i+ step/2 -1;
			merge(a,i,mid,mid+1,min(i+step-1,n));
		}
		//��ӡ�м��� 
	}
}

int main(){
	int a[] = {9,4,3,6,2,8,1,0,7,5};
	mergeSort(a,0,10);
	//
	vector<int> ve (begin(a),end(a));
	vector<int>::iterator ite;
	for(ite = ve.begin();ite!=ve.end();ite++){
		cout<<*ite<<" ";
	} 
	cout<<endl;
	//
	vector<int> ve2 (a,a+10);
	for(auto c:ve2){
		cout<<c<<" ";
	}
}
