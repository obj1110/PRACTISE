#include<iostream>
#include<cstring>
using namespace std;
bool array[10];
int main(){
	
	cout<<sizeof(array)<<endl;
	
	memset(array,true,sizeof(array));
	for(int i=0;i<10;i++){
		cout<<array[i]<<endl;
	}
	memset(array,false,sizeof(array));
	for(int i=0;i<10;i++){
		cout<<array[i]<<endl;
	}
}
