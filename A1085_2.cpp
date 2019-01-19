#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 100010;

int main() {
	//n��Ԫ���ܸ���,p���Ǹ�����,a���ҵ����� 
	int n,p,a[maxn];
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]); 
	}
	sort(a,a+n);
	//��ֵ��Ȼֵ�û��� ,����һ��ʼ����Ϊ-1��������max��ʵ�Ǻ�Ӧ�� 
	int ans = -1;
	for(int i=0;i<n;i++){
		//Ŀ�ľ���Ϊ���ҵ�int���͵�λ��
		//������upper����lowerֻ�ܷ���һ��int* ,Ϊ���ҵ���һ��a[j] > a[i]*p 
		int j = upper_bound(a+i+1,a+n,(long long)a[i]*p) - a;
		ans = max(ans,j-i);
	}
	printf("%d\n",ans); 
	return 0;
} 

