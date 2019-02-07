#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

struct bign{
	int d[1000];
	int len;
	//构造函数 ，将所有位置填充为0 
	bign(){
		memset(d,0,sizeof(d));
		len = 0;
	}
}; 

bign convert(char str[]){
	bign a;
	//反着顺序进行赋值 
	a.len = strlen(str);
	//数组的高位是数字的低位。 
	//或者觉得这种方法不好的话，可以用两个指针进行赋值操作。 
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

bign add(bign a,bign b){
	bign c;
	//carry表示进位的情况 
	int carry = 0;
	//从低位开始加起来 
	for(int i = 0 ; i < a.len || i < b.len ; i++ ){
		//表示当前两位相加的结果 
		int temp = a.d[i] + b.d[i] + carry;
		//当前的位置上是对10进行取模操作 
		c.d[c.len++] = temp%10;
		carry = temp/10; 
	}
	//如果你的进位到了最后还不是0，也就是要额外的生成一位 
	if(carry != 0){
		c.d[len++] = carry;
	}
	return c; 
}

bign sub(bign a,bign b){
	bign c;
	c.len = 0;
	//减法也是从低位开始 
	for(int i = 0 ;i<a.len || i<b.len;i++){
		//借一位 
		if(a.d[i] < b.d[i]) {
			a.d[i+1]--;
			a.d[i] += 10;	
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	//去除高位的0
	while(c.len- 1>=1 && c.d[len-1] == 0) {
		c.len--;
	}
	return c;
}

bign multi(bign a,int b){
	bign c;
	int carry =0;
	for(int i=0;i<a.len|| i<b.len;i++){
		int temp = a.d[i]*b + carry;
		
		c.d[c.len++] = temp%10;
		carry  = temp/10;
	}
	while(carry!=0){
		c.d[c.len++] = carry%10;
		carry /=10;
	}
	return c;
}

bign multi(bign a,bign b){
	bign c;
	c.len =0;
	
	int carry =0;
	for(int i=0;i<a.len || i<b.len;i++) {
		int temp = a.d[i]*b + carry; 
		c.d[c.len++] = temp%10;
		carry = temp/10;
	}
	
	while(carry != 0){
		c.d[c.len++] = carry % 10;
		carry/=10;
	}
	return c;
}

bign divide(bign a,bign b,int &r){
	bign c;
	c.len=a.len;
	for (int i=a.len-1;i>=0;i--){
		r = r*10 +a.d[i];
		if(r<b) c.d[i] = 0;
		else{
			c.d[i] = r/b;
			r = r%b;
		}
	}
	
}

void print(bign a) {
	for(int i=a.len-1; i>=0;i--){
		printf("%d",a.d[i]);
	}
}


int main(){
	char str1[1010],str2[1010];
	scanf("%s %s",str1,str2);
	bign a = convert(str1);
	bign b = convert(str2);
	print(add(a,b));
	return 0;
}
