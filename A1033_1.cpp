#include<iostream> 
#include<algorithm>
#include<cstring>
using namespace std;

const int maxsize = 510;
const int INF = 1000000;

struct station{
	double price,dis;
}st[maxn];

bool cmp(station a,station b){
	return a.dis<b.dis;
}

int main(){
	int n;
	double Cmax,D,Davg;
	scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&n);
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&st[i].price,&st[i].dis);
	}
	st[n].dis = D;
	st[n].price = 0.0;
	sort(st,st+n,cmp);
	if(st[0].dis != 0){
		printf("The maximum travel distance = 0.00\n");
	}
	else{
		int now =0;
		double ans = 0,nowTank =0,MAX =Cmax*Davg;
		while(now <n){
			int k = -1;
			double priceMin =INF;
			//下面这个for循环的意思就是只有两个条件都满足的时候才会继续for循环，因为你已经根据距离进行了排序
			//所以这其实就是相当于一个剪枝算法。实现寻找当前可达的最远车站。 
			for(int i=now+1;i<=n && st[i].dis - st[now].dis <= MAX;i++){
				if(st[i].price <priceMin) {
					priceMin = st[i].price;
					k = i;
					if(priceMin < st[now].price){
						break;
					}
				}
			}
		//如果无可达车站，就退出 
			if(k == -1) break;
			double need = (st[k].dis - st[now].dis)/Davg;
			if(priceMin < st[now].price) {
				if(nowTank < need){
					ans += (need -nowTank)*st[now].price;
					nowTank = 0;
				}
				else{
					nowTank -= need;
				}
			}
			else{
				ans += (Cmax -nowTank)*st[now].price;
				nowTank = Cmax -need;
			}
			now = k;
		}
		if(now == n){
			printf("%.2f\n",ans);
		}
		else{
			printf("The maximum travel distance = %.2f\n",st[now].dis + MAX);
		}
	}
	return 0;
} 
