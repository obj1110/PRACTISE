#include<iostream> 
#include<cmath>
using namespace std;

const int maxsize = 20;
int n;
//n��maxsizeҪС�ܶ࣬��������ȫ����ͬ����� 
int count = 0;
int p[maxsize]={0};
bool hashTable[maxsize]={false};

void gen(int index){
	if(index==n+1){
		bool flag = true;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++) {
				//��������˶Խ��ߵ���� 
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
