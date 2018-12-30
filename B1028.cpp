#include<iostream>
#include<cstring>

using namespace std;
//这种做法非常值得学习 
struct person{
  char name[6];
  int yy,mm,dd;
}temp, ans_elder, ans_young, left_bou, right_bou;

//注意左右边界都是可以取等号的。 

//判断a是不是小于b，也就是右边界判断
int Less(person a,person b){
	if(a.yy!=b.yy) return a.yy <= b.yy;
	else if(a.mm!=b.yy) return a.mm <= b.mm;
	else return a.dd <= b.dd;
		//注意最后一个只要直接判断就行，千万不要惯性思维加上一个条件比如:
//	else if(a.dd != b.dd)  这可是大错特错！！！ 
	
}
//也就是左边界判断 也可以用于判断长者和年轻人 
int More(person a,person b){
	if(a.yy!=b.yy) return a.yy >= b.yy;
	else if(a.mm!=b.yy) return a.mm >= b.mm;
	else return a.dd >= b.dd;
	//注意最后一个只要直接判断就行，千万不要惯性思维加上一个条件比如:
//	else if(a.dd != b.dd)  这可是大错特错！！！ 
} 
void init(){
	ans_young.yy = right_bou.yy = 2014;
	ans_elder.mm = ans_young.mm = right_bou.mm = 9;
	ans_elder.dd = ans_young.dd = right_bou.dd = 6;
	ans_elder.yy = left_bou.yy = 1814;	
} 

int main(){
  init();
  int num,a,b,c,cts = 0 ;
  scanf("%d",&num);
  for(int i=0;i<num;i++){
  	//注意字符串的scanf格式 
    scanf("%s %d/%d/%d",temp.name,&temp.yy,&temp.mm,&temp.dd);
    //判断产生日期是不是合法的 ，小于2014,9,6 
    if(More(temp,left_bou) && Less(temp,right_bou)){
    	cts++;
    	if(More(temp,ans_elder)) ans_elder = temp ;
    	if(Less(temp,ans_young)) ans_young = temp ;
	}
    // 判断年龄是不是合法的，小于200岁，也就是2014-9-6 - 生日 小于200年
  }
  if(cts == 0) printf("0");
  else printf("%d %s %s",cts,ans_elder.name,ans_young.name);
  return 0;
}
