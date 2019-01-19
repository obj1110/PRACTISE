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
		//�������ڵĳ�վ�ǲ���ȱ�ٵģ�
		//����һ����վ����ͨ����now��ֵ���иı� 
		double MAX = Cmax*Davg; 
		double money =0;
		//ֻҪ��û�е���վ����Ҫ���ϵĽ���ѭ�������ϵ�ѭ�� 
		while(now < n){
			//k�ǵ�ǰ��û���ҵ��ɴ����ٻ��ѳ�վ 
			int k = -1;
			double priceMin = INF; 
			//��仰���Ƿǳ��õ��أ�����һ��forѭ��������������
			//���Ⱦ��ǵ�ǰ�ɴ��Ȼ�󻨷����ٵĳ�վ 
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
