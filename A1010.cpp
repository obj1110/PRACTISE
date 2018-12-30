//#include<iostream>
//using namespace std;
//const int SIZE = 1010;
//int main(){
//  int a,b;
//  int flag =1;
//  int cts =0;
//  while (flag){
//  	  scanf("%d %d",&a,&b);
//	  
//	  if(b!= 0){
//	    
//	    if(cts > 0 ){
//	       printf(" ");
//	    }
//		cts++;
//	    printf("%d %d",a*b,(b-1));
//	  }
//	  else{
//	  	flag =0;
//	  } 
//  }
//  return 0;
//}
//
#include<cstdio>
#include<iostream>
using namespace std;
const int SIZE =1010;
int main(){
	int index[SIZE] = {0};//emmmmm这种方法要掌握，就是把一个数组全部初始化为0 
	int a,b,cts=0;
	for(int i=0;i<SIZE;i++){
		index[i] = 0;
	}
	//输入的个数需要使用EOF进行判断,然后EOF的判断在命令行中需要输入ctrl+Z 
	//输入的时候是首先输入高阶，输出的时候是首先输出低阶。你不能理所当然的认为所有的项都是异阶的。
	//这里的判断EOF不行啊 
	while(scanf("%d%d",&a,&b)== EOF ){
		index[b] += a;
	}
	//处理一种特殊情况就是0 0 多项式
	for(int i=SIZE-1;i>0;i++){
		if(index[i]!=0){

		}
	}
	return 0; 
}
