#include<iostream>
#include<cstring>
using namespace std;

int w[20]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char rule[20] ={'1','0','X','9','8','7','6','5','4','3','2'};

int main(){
  char num[20];
  int n;
  scanf("%d",&n);
  int flag =1;
  
  for(int i=0;i<n;i++){
  	int sum =0;
  	int sudo =0;
    cin>>num;
    
    //这里直接按照顺序来做就行了 
    for(int i=0;i<17;i++){
      if(num[i]>='0' && num[i]<='9'){
      	sum += w[i]*(num[i]-'0');	
	  }
    }
    
    for(int i=0;i<17;i++){
    	if(num[i]<'0' || num[0]>'9'){
            
			sudo =1;		
		}
	}
	if(sudo ==1){
		cout<<num<<endl;
	}
	else{
		if(rule[sum%11]==num[17]){
      		continue;
    	}
	    else{
	      cout<<num<<endl;
	      flag=0;
	    }
	}

  }
  if(flag==1){
    printf("All passed");
  }
  return 0;
}

