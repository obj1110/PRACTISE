//这个题的核心内容是struct的应用 

#include<iostream>
using namespace std;
struct Student{
  char name[15];
  char id[15];
  int score;
}temp,ans_max,ans_min;

int main(){
  int num;
  scanf("%d",&num);
  //其实说到底啊，并不需要string数组，只需要string就可以了。
  ans_max.score = -1;
  ans_min.score = 101;
  for(int i=0;i<num;i++){
    //这个东西的意思是，数组本身就是一种指针，这种字符串数组直接用数组名作为指针就行了
    scanf("%s%s%d",temp.name,temp.id,&temp.score);
    if(temp.score >ans_max.score) ans_max = temp;
    if(temp.score <ans_min.score) ans_min = temp;
  }
  printf("%s %s\n",ans_max.name,ans_max.id);
  printf("%s %s\n",ans_min.name,ans_min.id);
  return 0;
} 
