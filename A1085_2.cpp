#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 100010;

int main() {
	//n是元素总个数,p是那个参数,a是我的数组 
	int n,p,a[maxn];
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]); 
	}
	sort(a,a+n);
	//初值仍然值得怀疑 ,不过一开始设置为-1，与后面的max其实是呼应的 
	int ans = -1;
	for(int i=0;i<n;i++){
		//目的就是为了找到int类型的位置
		//单纯的upper或者lower只能返回一个int* ,为了找到第一个a[j] > a[i]*p 
		int j = upper_bound(a+i+1,a+n,(long long)a[i]*p) - a;
		ans = max(ans,j-i);
	}
	printf("%d\n",ans); 
	return 0;
} 

