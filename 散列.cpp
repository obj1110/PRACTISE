#include<iostream>
using namespace std;
const int maxsize = 100100;

//bool hashTable[maxn] = {false};
//与其说是散列，不如说更像是一个标记数组的感觉 
int hashTable[maxn] = {0};

int hashStrFunc(char array[],int length){
	int id =0;
	for(int i=0;i<len;i++){
		//因为你的目的是将一整个的字符串进行转换，转化的结果是一个巨大无比的数字。所以就是要用26进制转10进制。
		//将逻辑上的26进制数字转变为10进制数字。 
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
	//像是这种乘以10的其实就是在最后增加一位而已 
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
