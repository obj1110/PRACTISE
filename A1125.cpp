//哈夫曼树
//两两合并之后会发生减半
//问就是这些东西两两合并之后的结果长度
//感觉要出小数，越大的数字合并越晚 

#include<iostream>
#include<algorithm> 
#include<cstring>
#include<cmath>
using namespace std;
//简单做法，既然是小的先合并，那就在vector里面就可以实现 

//更简单的做法 result = (result + v[i]) / 2;
int main(){
	int n;
	scanf("%d",&n);
	double v[n];
	for(int i=0;i<n;i++){
		scanf("%lf",&v[i]);
	}

	//对于v进行排序，让小的在头边 
	int front = 0;
	sort( v + front , v+n );
//	while(front != n-1) {
//		v[front+1] = ( v[front] + v[front+1] )/2;
//		front++;
//		sort(v+front,v+n);
//	} 
	int front_value = v[0];
	for(int i=1;i<n;i++){
		front_value = (front_value + v[i])/2; 
	}
	cout<<(int)front_value;
	//结果要进行向下取整
	return 0; 
}
