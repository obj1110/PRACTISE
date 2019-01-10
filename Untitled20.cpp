#include<iostream> 
using namespace std;
int n;
bool hashTable[100010] = {false};
int p[100010];

void permuation(int index){
	if(index==n){
		for(int i =1;i<=n;i++){
			printf("%d",p[i]);
		}
		printf("\n");
		return;
	}
	for(int j=1;j<=n;j++){
		if(hashTable[j]==false){
			p[index] = j;
			hashTable[j] = true;
			permuation(index+1);
			hashTable[j] = false;
		}
	}
}

int main(){
	n =3 ;
	permuation(1);
	return 0;
}
