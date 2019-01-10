#include<iostream>
#include<cstring>

using namespace std;
const int size = 100010;
char str[size];
bool HashTable[255];

int main(){
	memset(HashTable,true,sizeof(HashTable));
	scanf("%s",array);	
	for(int i=0;i<strlen(array);i++){
		if(array[i]>= 'A' && array[i]<='Z'){
			array[i] = array[i] - 32 ;
		}
		HashTable[array[i]] = false;
	}
	scanf("%s",str);
	for(int i=0;i<strlen(str);i++){
		if(str[i]>='A' && str[i]<='Z'){
			//low���Ǵ�д��ĸ��Ӧ��Сд��ĸ�������� 
			int low = str[i] - 'A' +'a';
			//���ÿ��ǲ��������д��ԭ����Ϊ�����Ļ������Ǵ�д�䲻�ˣ���Сд������� 
			if(HashTable[low] == true && HashTable['+'] == true) {
				printf("%c",str[i]);
			}
			else if(HashTable[str[i]] == true){
				printf("%c",str[i]);
			}
		}
	}
	printf("\n");
	return 0;
}
