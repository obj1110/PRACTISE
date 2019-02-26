#include<iostream>
#include<map> 
#include<utility> 
using namespace std;
int main(){
	map<string,int> mp;
	mp.insert(make_pair("justin",12));
	mp.insert(make_pair("a",13));
	mp.insert(make_pair("B",15));
	for(auto& x:mp){
		cout<<x.first<<" "<<x.second<<endl;
	}
	auto it = mp.insert(mp.begin(),make_pair("d",10));
	mp.insert(it,make_pair("e",15));
	mp.insert(it,make_pair("f",16));
	mp.insert(it,make_pair("g",17)) ;
	for(auto& y:mp){
		cout<<y.first<<" "<<y.second<<endl;
	}
	cout<<"======================"<<endl;
	mp.emplace("x",10);
	mp.emplace("y",20);
	mp.emplace("z",320);
	for(auto& y:mp){
		cout<<y.first<<" "<<y.second<<endl;
	}
	return  0;
}
