#include<iostream>
#include<cstring>
#include<vector>
 
using namespace std;
int main(){
	////////////////ʹ��cstring��strtok���зָ� 
	//p�͹̶�ָ���һ�α��ָ������Ķ��� 
	char str[] = "a,b,c,d*e,f,g,h_i,*g*";
	char *p;
	p = strtok(str,",");
	while(p!=NULL){
//		printf("%s\n",p);
		p = strtok(NULL,",");
	}
	///////////////// �����ַ����зָ� 
	strcpy(str,"a,b,c,d*e,f,g,h_i,*g*");
	const char *split = "*_,";
	p = strtok(str,split);
	while(p!=NULL){
//		printf("%s\n",p);
		p = strtok(NULL,split);
	}
    //////////////////////////////////////
    char str2[] = "aEb#c@d!e*f_g-hEiEg";
//	char str2[] = "aEb#c@d!e*f_g-hEiEg";
	const char *split2= "E#!@#$%^&*()_-";
	char *ptr =strtok(str2,split2); 
	while(ptr!=NULL){
//		printf("%s\n",ptr);
		ptr = strtok(NULL,split2);
	}
	/////////////////////////////////////// 
	return 0;
}
