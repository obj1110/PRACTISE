#include<iostream>
using namespace std;

struct stu1{
	int id;
}stu2;

typedef struct stu3{
	int id;
}stu4;

int main(){
	stu2.id = 10;
	stu4 stu4_sample;
	stu4_sample.id = 20;
}

//C++中 typedef struct 和 struct 之间的区别就是
//typedef struct {} 类型昵称  //后面是一种类型名称
// struct{} 类型实例对象 

//C语言中  
//https://www.cnblogs.com/qyaizs/articles/2039101.html
