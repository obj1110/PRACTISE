#include<iostream>
#include<cmath>
#include<algorithm> 

using namespace std;

int n;
const int maxsize = 10;
//��ȫ���������ʾĳһ��������û�б� 
bool hashTable[maxsize] = {false};
int p[maxsize] = {0};

void gen(int index){
	if(index == n+1){
		count++;
		return;
	}
	for(int x =1;x<=n;x++){
		if(hashTable[x] == false){
			bool flag = true;
			for(int pre=1;pre <=n;pre++) {
				if(abs(index - pre))
			}
		}
	}


}


int main(){
	n =4;
	gen(1);
	return 0;
}
