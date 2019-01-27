#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<time>

using namespace std;

struct bign{
	int d[1000];
	int length;
	bign() {
		memset(d,0,sizeof(d));
		len = 0;
	}
}

bign convert(char s[]) {
	bign a;
	a.length = strlen(s);
	for(int i=0;i<a.length;i++){
		a.d[i] = str[a.len - i -1] -'0';
	}
	return a;
}

int main(){
	
}
