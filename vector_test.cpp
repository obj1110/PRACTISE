#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstdio.h> 
#include<set>

using namespace std;
int main(){
	vector<int> vi;
	vector<int>::iterator it = vi.begin();
	set<int> si;
	set<int>::iterator it;
	set<char>::iterator it2;
	
	int value = 100;
	si.erase(si.find(value));
	
	return 0;
}
