#include<iostream>
#include<cstring>
using namespace std;
const int maxsize = 100100;
int n;
bool hashTable[maxsize]={false} ;
int p[maxsize];

void gen(int index){
	if(index == n+1){
		for(int i=1;i<=n;i++){
			printf("%d",p[i]);
		}
		printf("\n");
		return;
	}
	for(int j=1;j<=n;j++){
		if(hashTable[j] == false){
			hashTable[j] = true;
			p[index] = j;
			gen(index+1);
			hashTable[j] = false;
		}
	}
}

int main(){
	memset(p,false,sizeof(p));
	int n;
	gen(1);
	return 0;
}
