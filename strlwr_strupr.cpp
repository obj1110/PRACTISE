#include<iostream> 
#include<cstring>
using namespace std;
int main(){
	char school[20];
	strcpy(school,"SCHOOL");
	strcpy(school,strlwr(school)); 
	cout<<school<<endl;
}
