#include<iostream>
#include<cstring>
using namespace std;
struct ite{
  char id[20];
  int yy,mm,dd;
}ear,lat,te1,te2;

void init(){
  ear.yy = 23;
  lat.yy = 0;
  ear.mm = 59;
  lat.mm = 00;
  ear.dd = 59;
  lat.dd = 00;
}

int More(ite a,ite b){
  if(a.yy!=b.yy ) return a.yy > b.yy;
  else if(a.mm != b.mm) return a.mm > b.mm;
  else return a.dd > b.dd;
}

int Less(ite a,ite b){
  if(a.yy!=b.yy ) return a.yy< b.yy;
  else if(a.mm != b.mm) return a.mm< b.mm;
  else return a.dd < b.dd;
}

int main(){
  //正因为没有init所以我没做出来= = 
  init();
  int num;
  scanf("%d",&num);
  for(int i=0;i<num;i++){
    scanf("%s %d:%d:%d %d:%d:%d",te1.id,&te1.yy,&te1.mm,&te1.dd,&te2.yy,&te2.mm,&te2.dd);
    strcpy(te2.id,te1.id);
    if(More(ear,te1)){
      ear = te1;
    }
    if(More(te2,lat)){
      lat = te2;
    }
  }
  printf("%s ",ear.id);
  printf("%s",lat.id);
  return 0;
}
