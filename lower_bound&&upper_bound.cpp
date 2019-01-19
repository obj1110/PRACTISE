#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 100100;
int array[maxn]= {4,10,11,30,69,70,96,110};
int main(){
	//返回如果要插入3的位置: 
	//lower_bound返回的结果是第一个>= key值的位置。 
	//upper_bound返回的是第一个<key值的位置 
	//数组总的大小 
	cout<<sizeof(array)/sizeof(array[0])<<endl;
	//插入3的具体位置 
	int pos1 = lower_bound(array , array+8 , 8) - array;
	int pos2 = upper_bound(array, array+8 , 8) - array;
	cout<<"pos1:"<<pos1<<" "<<"pos2:"<<pos2; 
	return 0;
}
