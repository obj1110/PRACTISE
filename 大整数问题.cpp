#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

struct bign{
	int d[1000];
	int len;
	//构造函数 
	bign(){
		memset(d,0,sizeof(d));
		len = 0;
	}
}; 

bign convert(char str[]){
	bign a;
	//反着顺序进行赋值 
	a.len = strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i] = str[a.len -i -1] - '0';
	}
	return a;
}
int compare(bign a,bign b) {
	if(a.len > b.len) return 1;
	else if(a.len < b.len) return -1;
	else{
		for(int i=a.len - 1;i>=0;i--){
			if(a.d[i] > b.d[i]) return 1;
			else if(a.d[i] < b.d[i] ) return -1;
		}
	} 
	return 0;
}

int main(){
	
}
