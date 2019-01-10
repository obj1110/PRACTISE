#include<iostream>
using namespace std;
const int size = 100000;
//由于所有的数值都不超过500，所以其实完全可以用hash思想来做题 
bool value[520];

int main(){
	memset{value,false,sizeof(value)};
	
	int n,m,temp;
	
	scanf("%d %d",&n,&m); 
	
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		value[temp] = true;
	}
	for(int i=0;i<=250;i++){
		if(value[i]==true && value[m-i]==true){
			cout<<i<<" "<<m-i<<endl;
			return 0;
		}
	}
	cout<<"No Solution";
	return 0;
}
