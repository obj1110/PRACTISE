#include<iostream>
#include<algorithm>
using namespace std;

struct g{
	float p; // 是价格 
	float d;   // 是距离 ，也就是离杭州的距离 
}gas[500];

bool cmp(g a,g b){
	return a.d < b.d;
}

int main(){
	float c,d,davg;
	int n;
	scanf("%f %f %f %d",&c,&d,&davg,&n);
	int i=0;
	for(i=0;i<n;i++){
		scanf("%f %f",&gas[i].p,&gas[i].d);
	}
	gas[n].p =0.0;
	gas[n].d = d;
	sort(gas,gas+n,cmp);
//	for(int i=0;i<=n;i++){
//		cout<<endl<<gas[i].d<<" "<<gas[i].p<<endl;
//	}
	float max = c*davg;
	float dis =0.0;
	float money =0.0;
	if(gas[0].d != 0.0){
		printf("The maximum travel distance = %0.2f",dis);
	}
	//
	bool flag = true;
	int now = 0;
	int next = now+1;
	while( flag == true ){
		if((gas[next].d - gas[now].d) > max){
			dis += max;
			printf("The maximum travel distance = %0.2f",dis);
			return 0;
		} 
		else{  //意思就是能到 
		
		 
//			if(gas[next].p <= gas[now].p){
//				dis += gas[next].d - gas[now].d;
//				money += dis*gas[now].p;
//				now = next;
//				next = now+1;
//				if(next == n){
//					money += (gas[next].d-gas[now].d)*gas[i].p;
//					printf("%0.2f",money);
//					return 0;
//				}
//			}
//			//如果票价更高 
//			else{ 
//				next = next +1;
//				if(next == n){
//					money += (gas[next].d-gas[now].d)*gas[i].p;
//					printf("%0.2f",money);
//					return 0;
//				}
//				else{
//					
//				}
//			}
		}
		if(next == n){
			money += (gas[next].d-gas[now].d)*gas[i].p;
			printf("%0.2f",money);
			return 0;
		}
	}
}
