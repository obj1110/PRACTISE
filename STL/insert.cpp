#include<iostream> 
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<unordered_map>
#include<>
using namespace std;
int main(){
	vector<int> myvector(3,100);
//	[100,100,100]
	vector<int>::iterator it;
	it = myvector.begin();
	it = myvector.insert(it,200);
//	[200,100,100,100]
	it = myvector.begin();
	vector<int> anothervector(2,400);
	myvector.insert(it+2,anothervector.begin(),anothervector.end());
//	[200,100,400,400,100]
	int myarray[] = {501,502,503};
	myvector.insert(myvector.begin(),myarray,myarray+3);
//	[501,502,503,200,100,400,400,100]
	return 0;
}
