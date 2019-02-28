#include<list> 
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<set>
using namespace std;
const int maxn = 10010;
const int inf = 0x3fffffff;
int main(){
	int array[10] = {231,4324,435,243,234,4576,568,345,234,13};
	vector<int> v(begin(array),end(array));
	for(auto& x:v) {
		cout<< x <<" ";
	}
	cout<<endl; 
	
	set<int> st;
	for(int i=0 ; i<10 ; i++)	{
		st.insert(i); 
	}
	cout<<*st.begin()<<" "<<*st.end()<<endl;
	int q_value = 5;
	cout<<count(st.begin(),st.end(),q_value);
	 
	return 0;
}
