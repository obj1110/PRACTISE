#include<iostream>
#include<algorithm>
#include<cstring> 
using namespace std;
const int maxn = 100010;
int coupon[maxn];
int product[maxn];
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&coupon[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&product[i]);
	}
	sort(coupon,coupon+n);
	sort(product,product+m);
	int ans;
	int i=0;
	int j=0;
	while(i < n && j < m && coupon[i]<0 && product[j]<0){
		ans += coupon[i]*product[j];
		i++;
		j++;
	}
	//当二者有一个是非负的就退出
	//从最大的进行遍历，二者用完一个就结束 
	i = n-1;
	j = m-1;
	while(i>=0 && j>=0 && coupon[i]>0 && product[j]>0) {
		ans += coupon[i]*product[j];
		i--;
		j--;
	}
	printf("%d\n",ans);
	return 0;
}
