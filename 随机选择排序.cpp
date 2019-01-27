#include<iostream> 
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<cmath>
#include<time.h>
#include<utility> 

using namespace std;

int randPartition(int a[],int left ,int right){
	srand((int)time(NULL));
	int pos = round((rand()*1.0)/RAND_MAX*(right-left+1) + left);
	//交换二者的位置 
	swap(a[pos],a[left]);
	//
	int temp = a[left];
	int i = left;
	int j = right;
	while(i<j){
		while(i<j && a[j]>temp) j--;
		a[i++] = a[j]; 
		while(i<j && a[i]< temp) i++;
		a[j--] = a[i];	
	}
	a[l] = temp;
	return l;
	
}
int randSelect(int a[],int left,int right ,int k){
	if(left == right) return a[left];
	
}

int main(){
	srand((unsigned)time(NULL)); 
	
	return 0;
}
