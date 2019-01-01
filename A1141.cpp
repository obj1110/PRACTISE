//这个题我主要是不知道应该是用什么样的数据结构。
//用数组感觉都不好
//感觉应该用hash结构 或者是结构体数组，也就是元素为结构体的数组 
#include<iostream>
#include<cstring>
using namespace std;
const int SIZE = 100010; 

struct schoolstruct{
  float tws; //权重 
  char name[8];//大小写不区分
  int n; //参赛人数 
}temp;

int main(){
  int N;
  float score;
  char id[8]; 
  char school;
  scanf("%d",&N);
  //结构体数组  
  schoolstruct item[N]; 
  //二维数组专门用于存放学校的名字，作为一个索引进行使用 
  char index[N][8]={};
  
  for(int i=0;i<N;i++){
  	int tws = 0;
    scanf("%s %f %s",id,score,school);
    
    //大小写转换函数strlwr strupr 
    //此外还有toupper 和 tolower 
    strcpy(school,strlwr(school));
    //输入 
    if(id[0]=='B'){
    	tws += score/1.5;
	}
	else if(id[0]=='A'){
		tws += score*1.0;
	}
	else if(id[0]=='T'){
		tws += score*1.5;
	}
	
//  下一步的处理成为一个问题，技术能力暂时不足以支撑
//   可以尝试的是dictionary 或者是 hashtable等等。 
//	for(int i=0;i<N;i++){
//        if(strcmp(index[i],school)){
//        	item[i].n++;
//			item[n].name = school;
//			item[n].tws += tws; 
//			break;
//		}
//		else if(){
//			
//		}
//	}
//    
  }

  // Rank School TWS Ns
  return 0;
}

