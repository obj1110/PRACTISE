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

//C++�� typedef struct �� struct ֮����������
//typedef struct {} �����ǳ�  //������һ����������
// struct{} ����ʵ������ 

//C������  
//https://www.cnblogs.com/qyaizs/articles/2039101.html
