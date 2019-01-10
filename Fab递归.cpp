#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 11;
int n;
itn P[maxn];
int hasht[maxn];

void generate(int index){
	if(index == n + 1 ) {
		for(int i=1;i<=n;i++){
			printf("%d",P[i]);
		}
		printf("\n");
		return;
	}
}

int main(){
	memset(hasht,false,sizeof(hasht));
	return 0;
}
