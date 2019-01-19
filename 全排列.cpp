#include<iostream>
using namespace std;

const int maxsize = 20;

int n;
int p[maxsize] = {0};
bool hashTable[maxsize] = {false};

void gen(int index){
	if(index == n+1){
		for(int i=1 ; i<=n ; i++){
			printf("%d",p[i]);
		}
		printf("\n");
		return;
	}
	for(int x=1;x<=n;x++){
		if(hashTable[x] == false){
			hashTable[x] = true;
			p[index] = x;
			gen(index+1);
			hashTable[x] = false;
		}
	}
}

int main(){
	n =3;
	gen(1)	;
	return 0;
}
