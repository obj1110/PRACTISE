#include<iostream>

#include<cstring>
using namespace std;


//char *strtok(char str[], const char *delim);

//注意事项就是，字符串要变的，将所有的分割符号替换为\0，也就是字符串结束标志，也就是为什么打印只剩下了helo的原因 
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
	//第一次传入要分割的字符串，以后只需要传入NULL即可
	cout<<"=============="<<endl;
	cout<<str<<endl;
	//str并不是真的剩下了hello，只不过是因为所有的分割符号成了\0,而打印的话，只打印到\0就停了
	//分隔符本质上是分隔符集合 
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

