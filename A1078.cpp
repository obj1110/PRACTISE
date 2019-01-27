#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

bool isPrime(int n){
  if(n<=1) return false;
  int sqr = (int)sqrt(n*1.0);
  for(int i=2;i<=sqr;i++){
    if(n%i==0) return false;
  }
  return true;
}

int main(){
  //m是用户定义的大小，n是输入的数据个数。
  //m要变成大于m的素数。
  int m,n,temp,position;
  scanf("%d %d",&m,&n);
  int size = m;
  if(isPrime(m)==false){
    size++;
    while(!isPrime(size)){
      size++;
    }
  }
  bool hashTable[size];
  memset(hashTable,false,size);
  
  for(int i=0;i<n;i++){
    scanf("%d",&temp);
    position = temp%size;
	if(hashTable[position]==false){
		hashTable[position] = true;
		printf("%d",position);
	}
	else{
		int add;
		//flag表示有没有最终成功的找到位置 
		int flag = false;
		for(int add = 1; add <=size;add++) {
			int index = (position+add*add)%size;	
			if(hashTable[index] == false){
				hashTable[index] == true;
				printf("%d",index);
				flag = true;
				break;
			}
		}
		if(flag== false) printf("-");
	}
	if(i!=n-1) printf(" ");
  }
  
  //如果不能输出位置就要输出一个-
}
