//��������
//�����ϲ�֮��ᷢ������
//�ʾ�����Щ���������ϲ�֮��Ľ������
//�о�Ҫ��С����Խ������ֺϲ�Խ�� 

#include<iostream>
#include<algorithm> 
#include<cstring>
#include<cmath>
using namespace std;
//����������Ȼ��С���Ⱥϲ����Ǿ���vector����Ϳ���ʵ�� 

//���򵥵����� result = (result + v[i]) / 2;
int main(){
	int n;
	scanf("%d",&n);
	double v[n];
	for(int i=0;i<n;i++){
		scanf("%lf",&v[i]);
	}

	//����v����������С����ͷ�� 
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
	//���Ҫ��������ȡ��
	return 0; 
}
