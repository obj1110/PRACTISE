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
  //m���û�����Ĵ�С��n����������ݸ�����
  //mҪ��ɴ���m��������
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
		//flag��ʾ��û�����ճɹ����ҵ�λ�� 
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
  
  //����������λ�þ�Ҫ���һ��-
}
