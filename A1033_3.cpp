#include<iostream>
#include<algorithm>
#include<cstring> 

using namespace std;

const double maxsize = 520;
const double INF = 1000000;

struct station{
	double price;
	double dist;
}st[maxsize];

bool cmp(station a,station b){
	return a.dist < b.dist;
}

int main(){
	double Cmax,D,Davg;
	int N;
	scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N);	
	for(int i=0;i<N;i++){
		scanf("%lf%lf",&st[i].price,&st[i].dist);
	}
	st[N].price = 0;
	st[N].dist = D;
	sort(st,st+N,cmp);
	if(st[0].dis != 0){
		printf("The maximum travel distance = 0.00\n");
	}
	else{
		int now =0 ;
		//现在所在的车站是不可缺少的，
		//而下一个车站可以通过对now赋值进行改变 
		double MAX = Cmax*Davg; 
		double money =0;
		//只要你没有到车站，就要不断的进行循环，不断的循环 
		while(now < n){
			//k是当前有没有找到可达最少花费车站 
			int k = -1;
			double priceMin = INF; 
			//这句话才是非常好的呢，就是一个for循环里面两个条件
			//首先就是当前可达的然后花费最少的车站 
			for(int i=now+1;i<=n && (st[i].dis - st[now].dis)<=MAX;i++){
				if(st[i].price <priceMin){
					priceMin = st[i].price;
					k = i;
					if(priceMin < st[now].price) {
						break;
					}
				}
			}
		}
	} 
	return 0;
}
