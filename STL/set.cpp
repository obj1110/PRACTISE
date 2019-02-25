#include<cstring>
#include<iostream>
#include<set>
#include<algorithm>

using namespace std;
const int maxn = 1010;
const int inf = 0x3fffffff;

set<int> st;
int main(){
	st.insert(1);
	st.insert(2);	
	st.insert(3);
//	for(auto ite = st.begin();ite!= st.end();ite++){
//		cout<<*ite<<endl;
//	}
	cout<<st.count(10)<<endl;
	cout<<st.count(3)<<endl;
 	
	return 0;
}
