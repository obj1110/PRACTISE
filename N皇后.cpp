#include<iostream> 
#include<cmath>
using namespace std;

const int maxsize = 20;
int n;
//n比maxsize要小很多，而不是完全的相同的两项。 
int count = 0;
int p[maxsize]={0};
bool hashTable[maxsize]={false};

void gen(int index){
	if(index==n+1){
		bool flag = true;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++) {
				//如果出现了对角线的情况 
				if(abs(i-j) == abs(p[i] - p[j])){
					flag = false;
				}
			}
		}
		if(flag == true ) count++;
		return;
	}
	for(int x=1;x<=n;x++) {
		if(hashTable[x] == false){
			p[index] = x;
			hashTable[x] = true;
			gen(index + 1);
			hashTable[x] = false;
		}
	}
}

void genp(int index){
	if(index == n+1){
		count++;
		return;
	}
	for(int x=1;x<=n;x++){
		if(hashTable[x] == false){
			
		}
	}
}
int main(){
	n = 4;
	gen(1);
	cout<<count;
	return 0;	
}
