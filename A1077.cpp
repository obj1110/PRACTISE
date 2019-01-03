#include<iostream>
#include<algorithm>
#include<cstring> 

using namespace std;
void rev(char array[]){
	//一定注意函数的参数是数组而不是指针
	//此外注意函数的返回值是void而不是额外的东西，即使有也应该是引用的问题 
	int len = strlen(array);
	for(int i=0;i<len/2;i++){
		//这个函数一定要注意，一开始没有写成len-i-1的形式，也就是应该注意下标问题 
		char temp = array[i];
		array[i] = array[len-i-1];
		array[len-i-1] = temp;
	}
}
int main(){
	//用自定义的函数进行翻转 
//	char str[260];
//	scanf("%s",str);
//	rev(str);
	//用algorithm的reverse函数进行翻转 
//	reverse(str,str+strlen(str));
	
	
	int n; 
	scanf("%d",&n);
	//每一行最多就是256个 
	char suffix[260];
	char temp[260];
	//特例就是如果长度为1的话，就直接返回这个数组就行了
	getchar();
	gets(suffix);
	
	rev(suffix); 
	int pos = strlen(suffix);
	//pos就是数组的长度情况 
	//getchar用于读取换行符号
	//gets用于读取一行进来直到下一个换行符号 
	
	
	for(int i=1;i<n;i++){
		int len = 0;
		//这里一定不可以用scanf因为scanf用空格进行分割，起码也要getline(两个参数)
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
	
	//别忘了最后输出的时候要reverse回来 ，其实不用。 
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
