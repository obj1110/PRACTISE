#include<iostream>
using namespace std;
const int maxsize = 12;
int n;
bool used[maxsize] = {false};
int p[maxsize];

void gen(int index){
	if(index == (n+1)){
		for(int i=1;i<=n;i++){
			printf("%d",p[i]);
		}
		printf("\n");
		return;
	}
	for(int j=1;j<=n;j++) {
		if(used[j] == false){
				p[index] = j;
			used[j] == true;
			gen(index + 1);
			used[j] = false;
		}
	}
}
int main(){
	n =3;
	gen(1);
	return 0;
} 
