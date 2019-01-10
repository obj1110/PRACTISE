#include<iostream>
using namespace std;
const int maxsize =12;
int n;
bool valid[maxsize];
int p[maxsize];


void gen(int index){
	if(index == n+1){
		for(int i=1;i<=n;i++){
			printf("%d",p[i]);
		}
		printf("\n");
	}
	else if(index !=(n+1)){
		for(int j=1;j<=n;j++){ 
			if(valid[j] == false){
				p[index] = j;
				valid[j] = true;
				gen(index+1);
				valid[j] = false;
			}
		}
	}
}
int main(){
	n = 4;
	gen(1);
	return 0;
} 
