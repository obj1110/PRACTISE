#include<iostream> 
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
	char str[] ="a,sd,f,g,g,h,j";
	char *p;
	p = strtok(str,",");
	cout<<p<<endl;
	while(p!=NULL){
		p = strtok(NULL,",");
		cout<<p<<endl;
	}
	return 0;
}

