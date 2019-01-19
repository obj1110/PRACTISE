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
	//��������һ���ǷǸ��ľ��˳�
	//�����Ľ��б�������������һ���ͽ��� 
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
