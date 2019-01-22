#include<iostream>
#include<algorithm>
using namespace std;

//双闭区间 
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
//左闭右开
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
//双开
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
//作者：zzzzzBelial 
//来源：CSDN 
//原文：https://blog.csdn.net/qq_42018521/article/details/81540863 
//版权声明：本文为博主原创文章，转载请附上博文链接！

int main(){
	
}
