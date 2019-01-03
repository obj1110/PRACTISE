#include<iostream>
#include<algorithm>
using namespace std;
const int maxsize = 100000;

int coupon[100010];
int value[100010];

int cmp(int a,int b) {
	return a<b;
}

int main(){
  long NC,NP;
  long temp;
  scanf("%ld",&NC);
  for(int i=0;i<NC;i++){
    scanf("%ld",&coupon[i]);
  }
  scanf("%ld",&NP);
  for(int i=0;i<NC;i++){
    scanf("%ld",&value[i]);
  }
  
  sort(coupon,coupon+NC,cmp);
  sort(value,value+NP,cmp);
  
  long sum =0;
  int i=0;
  int j =0;
  for(;i<NC && j<NP;i++,j++){
  	if(coupon[i] <0 && value[j]<0){
  		sum += coupon[i]*value[j];
	  }
	  else if(coupon[i]>0 && product[j]>0) {
	  	sum+= coupon[i]*value[j];
	  }
	  else{
	  	sum+= coupon[i]*value[j];
	  }
  }
  printf("%ld",sum);
  return 0;
}
