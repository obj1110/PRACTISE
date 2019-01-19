#include<iostream>
#include<cstring>

using namespace std;
const int maxsize = 10010;
char array[maxsize];
int flag[8];
char index[6] = {'P','A','T','e','s','t'};

int main(){
  memset(flag,0,sizeof(flag)); 
  cin.getline(array,maxsize);
//  while(scanf("%c",&char_name)!=EOF)  
  for(int i=0;i<=strlen(array);i++){
  	if(array[i] == 'P') flag[0]++;
  	else if(array[i] == 'A') flag[1]++;
  	else if(array[i] == 'T') flag[2]++;
  	else if(array[i] =='e') flag[3]++;
  	else if(array[i]=='s') flag[4]++;
  	else if(array[i]=='t') flag[5]++;
  } 
  //
  for(int i=0;i<=5;i++){
  	cout<<flag[i]<<endl;
  }
  bool control = true;
  //
  while(control){
  	int symbol =6;
  	for(int i=0;i<6;i++){
  		if(flag[i]>0){
  			printf("%c",index[i]);
  			flag[i]--;
		}
		else if(flag[i] == 0){
		  	symbol--;
		}
  	}	
  	if(symbol == 0) control = false;
  }
  return 0;
}
