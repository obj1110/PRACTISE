#include<iostream>
using namespace std;
void swap(int &a,int &b){
	int temp = a;
	a = b;
	b= temp;
}

int d[100005];

int main(){
	int n,m,a,b,sum,temp;
	sum =0;//��һ�����븳��ֵ
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		sum += d[i];
	}

	scanf("%d",&m);
	for(int i=0;i<m;i++){
		//��һ�����0������Ҫ
		temp = 0;  
		scanf("%d %d",&a,&b);
		if(a>b) swap(a,b);
		for(int j=a;j<b;j++){
			temp += d[j];
		}
		temp = min(temp,(sum-temp));
//		temp = (temp > (sum-temp))? (sum-temp):temp; 
		printf("%d\n",temp);
	}
	return 0;
}
