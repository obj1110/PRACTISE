#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;
//Ҳ����˵�����Ŀռ�ԭ��Ҫ���ַ������ַ���Ŀ��һ����Ŀ����Ϊ��������ַ�����β��\0�еط������ 
int main(){
	string str = "0123456789";
	char str1[11] = "0123456789";
	char str_use[11];
	
	strcpy(str_use,str1);
	cout << str_use;
	return 0;
}
