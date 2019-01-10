#include<cstring>
#include<iostream> 
using namespace std;
int main(){
	
	char array[100]="12345678";
	int n;
	sscanf(array,"%d",&n);
	printf("%d\n",n);
	
	sprintf(array,"%d",n);
	printf("%s\n",array);
	
	int a;
	double b;
	char c[100];
	string d;
	char str[100]="08:10.0,Hello world!";
	sscanf(str,"%d:%lf,%s",&a,&b,c);
	printf("a = %d ,b = %lf, c =  %s\n",a,b,c);
	
	sprintf(str,"%d:%0.1lf,%s",a,b,c);
	printf("%s",str);
	
	return 0;
}
