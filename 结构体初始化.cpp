#include<iostream>
#include<cstring>
using namespace std;

struct item{
	int id;
	char name[20];
	//四大构造函数 
	item(){};
	item(int _id,char _name[20]){
		id = _id;
		strcpy(name,_name);
	}
	item(int _id){
		id = _id;
	}
	item(char _name[20]){
		strcpy(name,_name);
	}
}stu;

struct item2{
	int id;
	char name;
//	item2(int _id,char _name):id(_id),name(_name){};
	stu2(int _id,char _name){
		id = _id;
		name = _name; 
	}
}stu2; 

int main(){
	item Ren = item(1,"ren");
	cout<<Ren.name<<endl;
	cout<<Ren.id<<endl;
}
