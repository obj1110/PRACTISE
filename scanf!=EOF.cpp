#include<cstdio>
#include<iostream>
using namespace std;
const int SIZE =1010;
int main(){
	int index[SIZE] = {0};//emmmmm这种方法要掌握，就是把一个数组全部初始化为0 
	int a,b,cts=0;
	//输入的个数需要使用EOF进行判断
	//输入的时候是首先输入高阶，输出的时候是首先输出低阶。你不能理所当然的认为所有的项都是异阶的。 
	while(scanf("%d%d",&a,&b)!=EOF){
		index[b] += a;
	}
}
