#include<iostream> 
#include<cstring>
#include<vector>

using namespace std;
int array[10];

int main(){
	cout<<sizeof(array)<<endl;
	
	cout<<sizeof(array[0])<<endl;
	 
    cout<<sizeof(array)/sizeof(array[0])<<endl;
    
	memset(array,-1,sizeof(array));
	cout<<"================" <<endl;
	vector<int> index(array,array+10);
	vector<int>::iterator ite;
	for(ite = index.begin();ite!= index.end();ite++){
		cout<<*ite<<endl;
	}
}
