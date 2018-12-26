#include<iostream>
using namespace std;
int main(){
	long a,b;
	scanf("%d %d",&a,&b);
	a = a+b;
	if(a==0) {
		cout<<"0"<<endl;	
		return 0;
	}
	if(a<0) {
		cout<<"-";
		a = a*(-1);
	}
	string num = to_string(a);
	int length = num.length();
	for(int i=0;i<length;i++){
		cout<<num[i];
		if((length-i)%3==1 && i!= (length-1)) cout<<",";
	}
	return 0;
}
