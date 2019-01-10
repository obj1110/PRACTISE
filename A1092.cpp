#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;
const int maxsize = 1100;
int HashTable[255];
char str1[maxsize];//source
char str2[maxsize];//target

int main(){
  memset(HashTable,0,sizeof(HashTable));
  scanf("%s",str1);//source
  scanf("%s",str2);//target 
  for(int i=0;i<strlen(str1);i++){
  	//����ͳ���ҿ��Ի�õ����Ӹ��� 
    HashTable[str1[i]]++;
  }
  for(int i=0;i<strlen(str2);i++){
    HashTable[str2[i]]--;
  }
  //��������˸�ֵ��˵���϶��ǲ����������еĸ�ֵ��Ӳ����
  //���һֱû�г��ָ�ֵ��˵���϶��ǹ��ˣ������е���ֵ��Ӳ���� 

  int flag = 1;
  int negative = 0;
  int positive = 0;
  for(int i=0;i<sizeof(HashTable)/sizeof(HashTable[0]);i++){
    if(HashTable[i]<0) {
    	negative += HashTable[i];
    	flag = 0;	
	}
	else{
		positive+= HashTable[i];
	}
  }
  if(flag ==0 ){
  	printf("No %d",fabs(negative));
  }
  else{
  	printf("Yes %d",positive);
  }
  return 0;
}
