#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

bool isPrime(int n){
  if(n<=1) return false;
  int sqr = (int)sqrt(1.0*n);
  for(int i=2;i<=sqr;i++){
    if(n%i == 0){
      return false;
    }
  }
  return true;
}

int main(){
  int m,n;
//  scanf("%d %d",&m,&n);
  m =5 ;
  n =27;
  
  
  int cts = 0 ; 
  int cnt = 0 ;
  for(int i =2;cts<=n;i++){
  	if(isPrime(i)){
  		cts++;
  		if(cts>=m && cts<=n){
  			cnt++;
  			printf("%d",i);	
  			
  			if( cnt%10 == 0 ){
  				printf("\n");
			}
			else if(cnt==(n-m+1)){
				return 0;
			}
			else{
				printf(" "); 
			}
			
		  }
	  }
  }
  return 0;
}
