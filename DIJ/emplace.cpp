#include<vector>
#include<iostream>
using namespace std;
vector<int> array (3,10);
int main(){
	array.emplace(array.begin(),100);
	array.emplace(array.begin()+1,200);
	//
	array.emplace(array.end(),300);
	//
	auto iterator = array.emplace(array.begin()+1,value2insert);
//	iterator equals the array.begin()+1 
	for(auto & x:array){
		cout<<x<< endl;
	}
	return 0;
}
