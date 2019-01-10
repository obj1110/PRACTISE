#include<iostream> 
using namespace std;
const int MAXSIZE = 100010;
int hashTable[26*26*26+10];
int HashFunc(char S[],int len){
	int id = 0;
	for(int i=0;i<len;i++){
		id =id*26 +S[i]-'A'; 
	}
	return id;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;iz<n;i++){
		scanf("%s",S[i]);
		int id = HashFunc(S[i],3); 
		HashTablep[id]++;
	}
	for(int i=0;i<m;i++){
		scanf("%s",temp); 
		int id = HashFunc(temp,3);
	} 
	return 0;
}
