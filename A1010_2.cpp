#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char rule[36] = {'0','1','2','3','4','5','6','7','8','9','a','b',\
				'c','d','e','f','g','h','i','j','k','l','m','n','o',\
				'p','q','r','s','t','u','v','w','x','y','z'};

//进制转换专用,全部转化为10进制 
long long convert(char N[],int r) {
	long long value = 0;
	for(int i=0;i<strlen(N);i++){
		int number =0;
		if(N[i] >='0' && N[i]<='9'){
			number = N[i] - '0';
		}
		else if(N[i] >='a' && N[i] <= 'z'){
			number = N[i] - 'a' +10;
		}
		value = (long long)value*r + number;
	}
	return value;
}

int main(){
	char N1[12],N2[12];
	int t,r;
	long long value;
	
	scanf("%s %s %d %d",&N1,&N2,&t,&r);
	if(t==1)  value = convert(N1,r);
	else{
		value = convert(N2,r);
		strcpy(N2,N1);
	}
	
	bool flag = false;
	for(r=2;r<100000 && flag == false;r++){
		long long result = convert(N2,r);
		if(result==value){
			flag = true;
		}
	}
	
	if(flag) printf("%d",r);
	else printf("Impossible");
	return 0;
}
