#include<iostream>
#include<cstring>
using namespace std;

const int maxsize = 100010; 
int n ;
bool hashTable[maxsize]={false};
int p[maxsize];

void gen(int index){
	if(index == n){
		for(int i=1;i<= n;i++){
			printf("%d",p[i]);
		}
		printf("\n");
		return;
	}
//	else{
		for(int j=1;j<=n;j++){
			if(hashTable[j] == false){
				p[index] = j;
				hashTable[j] = true;
				gen(index+1);
				hashTable[j] = false;
			}
		}
//	}
} 
int main(){
	memset(hashTable,false,sizeof(hashTable));
	n =3 ;
	gen(1);
	return 0; 
} 
