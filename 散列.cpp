#include<iostream>
using namespace std;
const int maxsize = 100100;

//bool hashTable[maxn] = {false};
//����˵��ɢ�У�����˵������һ���������ĸо� 
int hashTable[maxn] = {0};

int hashStrFunc(char array[],int length){
	int id =0;
	for(int i=0;i<len;i++){
		//��Ϊ���Ŀ���ǽ�һ�������ַ�������ת����ת���Ľ����һ���޴��ޱȵ����֡����Ծ���Ҫ��26����ת10���ơ�
		//���߼��ϵ�26��������ת��Ϊ10�������֡� 
		id = id*26 +(array[i] - 'A');
	}
	return id;
} 

int hashStrFunc2(char array[],int length) {
	int id =0;
	for(int i=0;i<len;i++){
		if(array[i]>'a'){
			id =id*52 +(array[i] - 'a') +26;
		}
		else if(array[i]>='A' && array[i]<='Z'){
			id = id*52 +(array[i]- 'A');
		}
	}
	return id;
}

int hashNumStrFunc3(char S[],int length){
	int id =0;
	for(int i=0;i<length;i++){
		if(array[i] > 'a'){
			id = id*62 + array[i]-'a'+36;
		}
		else if(array[i]>='A' && array[i]<='Z'){
			id =id*62 + array[i]-'A' + 10;
		}
		else if(array[i]>='0' && array[i]<='9'){
			id =id*62 + array[i] - '0';
		}
	}
	return 0;
}
int HashNumStrFunc2(char S[],int length){
	int id = 0;
	for(int i=0;i<len -1;i++)+{
		id = id *26 + (S[i] - 'A');
	}
	//�������ֳ���10����ʵ�������������һλ���� 
	id = id *10 +(S[len-1]-'0');
	return id;
} 
int main(){
	int n,m,x;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		hashTable[x] = 1;
	}
	for (int i=0;i<m;i++){
		scanf("%d",&x);
		if(hashTable[x] == 1) {
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
