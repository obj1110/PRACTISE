#include<iostream>

#include<cstring>
using namespace std;


//char *strtok(char str[], const char *delim);

//ע��������ǣ��ַ���Ҫ��ģ������еķָ�����滻Ϊ\0��Ҳ�����ַ���������־��Ҳ����Ϊʲô��ӡֻʣ����helo��ԭ�� 
int main(){
	char str[] = "hello,every,one,good,night,oho";
	char* cpystr= str;
	cout<<*cpystr<<endl;
	cout<<cpystr<<endl;
	cout<<"=============="<<endl;
	
	const char* delimter = ",";
	char *p = strtok(str,delimter);
	do{
		cout<<p<<endl;
	}while(p = strtok(NULL,delimter));
	//��һ�δ���Ҫ�ָ���ַ������Ժ�ֻ��Ҫ����NULL����
	cout<<"=============="<<endl;
	cout<<str<<endl;
	//str���������ʣ����hello��ֻ��������Ϊ���еķָ���ų���\0,����ӡ�Ļ���ֻ��ӡ��\0��ͣ��
	//�ָ����������Ƿָ������� 
	cout<<"=============="<<endl;
	char str1[] = "hello=every,one=good.night!oho";
	const char delimeters[] = ",.!=";
	char *p1;
	p1 = strtok(str1,delimeters);
	do{
		cout<<p1<<endl;	
	}while( p1 = strtok(NULL,delimeters));
	return 0;
}

