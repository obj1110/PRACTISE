#include<iostream> 
#include<cstring>
using namespace std;
int n =3;
bool valid[12] = {false};
int p[12];

void gen(int index){
	if(index == n){
		for(int i=1;i<=n;i++){
			printf("%d",p[i]);
		}
		printf("\n");
		//这个return到底是什么意思，return到什么地方呢 
		return;
	}
	for(int j=1;j<=n;j++) {
		if(valid[j]==false){
			valid[j]= true;
			p[index] = j;
			gen(index+1);
			valid[j] = false;
		}
	}
}
int main(){
	memset(valid,false,sizeof(valid));
	n =3 ;
	gen(1);
	return 0;
}
