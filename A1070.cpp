#include<iostream>
#include<algorithm>
using namespace std;

struct cake{
	int store;
	float profit;
	float price;
}Cake[1000];

bool cmp(cake a,cake b){
	return a.price > b.price;
}
 

int main(){
	int n,total;
	scanf("%d %d",&n,&total);
	
	for(int i=0;i<n;i++){
		scanf("%d",&Cake[i].store);
	}
	for(int i=0;i<n;i++){
		scanf("%f",&Cake[i].profit);
		Cake[i].price = Cake[i].profit/Cake[i].store;
	}
	sort(Cake,Cake+n,cmp);
	float profit = 0.0;
	for(int i=0;i<n;i++){
		if(total > Cake[i].store){
			profit += Cake[i].profit;
			total -= Cake[i].store;
		}
		else if(total <= Cake[i].store){
			profit += Cake[i].price * total;
			break;
		}
	}
	printf("%0.2f",profit);
	return 0;
}
