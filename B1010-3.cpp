#include<iostream> 
using namespace std;
const int SIZE = 1010;
int main(){
	int a,b,count=0;
	int index[SIZE]={0};

	while(scanf("%d %d",&a,&b)!=EOF){
		index[b] += a;
	}
	for(int i=0;i<1000;i++){
		index[i] = index[i+1]*(i+1);
		if(index[i]!=0) count++;
	}
	index[1000] = 0;
	if(count == 0) {
		printf("0 0");
		return 0;	
	}
	for(int i =999 ;i>=0;i--){
		if(index[i]!=0){
			printf("%d %d",index[i],i);
			count--;
			//这个输出空格一定要放在里面，不然就是格式错误。 
			if(count>0) printf(" ");
		}
	}
	return 0;
}
