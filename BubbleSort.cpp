#include<iostream>
#include<algorithm>
using namespace std;
const int maxsize = 100040;
int array[maxsize];
int main(){
	int n,flag =1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>array[i];
	}
	for(int i=n-1;i>=0;i--){
		flag = 0;
		for(int j=0;j<i;j++){
			if(array[j] < array[j+1]){
				swap(array[j],array[j+1]);
				flag = 1;
			}
		}
		if(flag == 0) break;
	}
	vector<int> index(array,array+n);
	vector<int>::iterator ite; 
	for(ite = index.begin();ite!=index.end();ite++){
		cout<<*ite<<endl;
			}
	return 0;
}
