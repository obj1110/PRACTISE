#include<iostream>
#include<algorithm>
#include<cstring> 

using namespace std;
void rev(char array[]){
	//һ��ע�⺯���Ĳ��������������ָ��
	//����ע�⺯���ķ���ֵ��void�����Ƕ���Ķ�������ʹ��ҲӦ�������õ����� 
	int len = strlen(array);
	for(int i=0;i<len/2;i++){
		//�������һ��Ҫע�⣬һ��ʼû��д��len-i-1����ʽ��Ҳ����Ӧ��ע���±����� 
		char temp = array[i];
		array[i] = array[len-i-1];
		array[len-i-1] = temp;
	}
}
int main(){
	//���Զ���ĺ������з�ת 
//	char str[260];
//	scanf("%s",str);
//	rev(str);
	//��algorithm��reverse�������з�ת 
//	reverse(str,str+strlen(str));
	
	
	int n; 
	scanf("%d",&n);
	//ÿһ��������256�� 
	char suffix[260];
	char temp[260];
	//���������������Ϊ1�Ļ�����ֱ�ӷ���������������
	getchar();
	gets(suffix);
	
	rev(suffix); 
	int pos = strlen(suffix);
	//pos��������ĳ������ 
	//getchar���ڶ�ȡ���з���
	//gets���ڶ�ȡһ�н���ֱ����һ�����з��� 
	
	
	for(int i=1;i<n;i++){
		int len = 0;
		//����һ����������scanf��Ϊscanf�ÿո���зָ����ҲҪgetline(��������)
		getchar();
		gets(temp);
		rev(temp);
		for(int i=0;i<pos && i<strlen(temp);i++){
			if(suffix[i] == temp[i]){
				len++;
			}
		}
		if(len < pos){
			pos =len;
		}
	}
	
	//��������������ʱ��Ҫreverse���� ����ʵ���á� 
	if(strlen(suffix)==0){
		printf("nai");
		return 0;
	}
	
	rev(suffix);
	for(int i=pos; i<strlen(suffix);i++){
		printf("%c",suffix[i]); 

	} 
	return 0;
}
