#include<iostream>
using namespace std;
int n;
bool flag[12] = {false};
int p[12];

void gen(int index){
	if(index == n+1){
		for(int i=1;i<=n;i++){
			printf("%d",p[i]);
		} 
		printf("\n");
		return;
	}
	for(int j=1;j<=n;j++){
		if(flag[j]== false){
			p[index] = j;
			flag[j] = true;
			gen(index +1);
			flag[j] = false;
		}
	}
}

int main(){
	n =3;
	gen(1);
	return 0;
}
