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
		//���return������ʲô��˼��return��ʲô�ط��� 
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
