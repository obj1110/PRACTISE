#include<iostream> 
using namespace std;
int main(){
	char str[40];
	char temp[40];
	int a;
	char sen[40] = "ren is 23 years old.";
	sscanf(sen,"%s %s %d",str,temp,&a);
	char str2[40];
	sprintf(str2,"%s -> %d",str,a);
	printf("%s",str2);
	return 0;
}
