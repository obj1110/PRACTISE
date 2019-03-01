#include<iostream>
#include<set> 
using namespace std;
set<int> st;
int main(){
	int i ;
	for(i = 11;i< 20;i++){
		st.insert(i);
	}
	auto it = st.find(5);
	if(it==st.end()){
		printf("No FOUND!\n");
	}
	it = st.find(11);
	if(it != st.end()){
		printf("YES FOUND\n");
	}
	return 0;
}
