#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct item{
  char name[10];
  int age;
  char wealth[10];
}stu[100100];

int cmp1(item a,item b){
	//这句话是重点要处理的，尤其是要考虑是不是会出现一个负号或者两个负号的问题 
  	if(a.wealth != b.wealth) {
  	char syma = a.wealth[0];
  	char symb = b.wealth[0];
  	if(syma=='-' && symb !='-') return -1;
  	else if(syma!='-' && symb =='-') return 1;
	else if(syma!='-' && symb !='-') return strcmp(a.wealth,b.wealth)>=0;
  	else if(syma =='-' && symb =='-') {
  		char tempa[10];
  		char tempb[10];
  		for(int i=0;i<strlen(a.wealth)-1;i++){
  			tempa[i] = a.wealth[i+1];
		  }
		for(int i=0;i<strlen(b.wealth)-1;i++){
			tempb[i] = b.wealth[i+1];
		}
		//因为是负数，所以我们的处理结果应该和正数的正好相反 
		return strcmp(tempa,tempb)<=0;
	  }
  	}
  	else if(a.age!=b.age) return a.age<=b.age;
  	else  return strcmp(a.name,b.name)<=0;
}

int cmp(item a,item b){
  if(a.wealth != b.wealth) return strcmp(a.wealth,b.wealth)>=0;
  else if(a.age!=b.age) return a.age<=b.age;
  else return strcmp(a.name,b.name)<=0;
}

int main(){
  int N,K;
  scanf("%d,%d",&N,&K);
  int count =0;
  for(int i=0;i<N;i++){
    scanf("%s %d %s",stu[i].name,&stu[i].age,&stu[i].wealth);
    printf("%s %d %s\n",stu[i].name,stu[i].age,stu[i].wealth);
    count++;
  }
  cout<<"--------------"<<endl;
  sort(stu,stu+count,cmp);
  for(int i=0;i<=count;i++){
  	printf("%s %d %s\n",stu[i].name,stu[i].age,stu[i].wealth);
  }
  
  
//  int M,agemin,agemax;
//  int queryindex =1 ;
//  
//  for(int indtemp=0;indtemp<K;indtemp++){
//    scanf("%d %d %d",&M,&agemin,&agemax);
//    //最好是马上输出
//    printf("Case #%d:\n",queryindex);
//    queryindex++;
//    //
//    int cts = 0;
//    for(int i=0;cts<M && i<N;i++){
//      if((stu[i].age >= agemin) &&(stu[i].age <= agemax)){
//        printf("%s %d %ld\n",stu[i].name,stu[i].age,stu[i].wealth);
//        cts++;
//      }
//    }
//    if(cts == 0 ){
//      printf("None\n");
//    }
//  }
  return 0;
}
