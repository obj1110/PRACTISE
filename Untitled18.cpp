#include<iostream> 
#include<cstring>
using namespace std;

const int maxsize = 12;
int n;
int p[maxsize];
bool valid[maxsize];

void gen(int index){
	if(index == n){
		for(int i=1;i<=n;i++){
			printf("%d",p[i]);	
		}
		printf("\n");
	}
	for(int j=1;j<=n;j++){
		if(valid[j]==false){
			valid[j] = true;
			p[index] = j;
			gen(index+1) ;
			valid[j] = false;
		} 
	}
}
int main(){
	memset(valid,false,sizeof(valid));
	gen(1);
	return 0;	
}
