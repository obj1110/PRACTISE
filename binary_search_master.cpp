#include<iostream>
#include<algorithm>
using namespace std;

//˫������ 
int binary_search(int a[],int size,int p){
	int l=0;
	int r = size -1;
	while(l<=r) {
		int mid = l + (r-l)/2;
		if(p == a[mid]) return mid;
		else if(p > a[mid]) l = mid+1;
		else r = mid -1;
	}
}
//����ҿ�
int binary_search1(int a[],int size ,int p) {
	int l = 0;
	int r = size -1;
	while(l<r){
		int mid =  l +(r-l)/2;
		if(p== a[mid])  return mid;
		else if(p < a[mid]) r = mid;
		else l = mid;
	}
}
//˫��
int binary_search(int a[],int size,int p)
{
    int L = 0;
    int R = size - 1;
    while(R-L > 1){
        int mid = L + (R-L)/2;
        if(a[mid] == p)
            return mid;
        else if(p < a[mid]){
            R = mid;
        }
        else{
            L = mid;
        }
    }
}

//--------------------- 
//���ߣ�zzzzzBelial 
//��Դ��CSDN 
//ԭ�ģ�https://blog.csdn.net/qq_42018521/article/details/81540863 
//��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�

int main(){
	
}
