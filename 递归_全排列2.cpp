#include<iostream>
using namespace std;
const int maxsize = 100010;
int n ;
bool flag[maxsize]={false};
int p[maxsize];

void gen(int index){
	if(index == n+1){
		for(int i=1;i<=n;i++){
			printf("%d",p[i]);
		}
		printf("\n");
		return;
	}
	for(int x = 1;x<=n;x++){
		if(flag[x] == false){
			flag[x] = true;
			p[index] = x;
			gen(index +1);
			flag[x] = false;
		}
	}
}

int main(){
	n =3;
	gen(1);
	return 0;
}
