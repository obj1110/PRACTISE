//���������е�Ԫ�ؾ���ƽ������������
//�����������е�Ԫ�صĲ�ֵ��� 
//������������������ƽ������	 
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<algorithm> 
#include<cmath>
using namespace std;
int n,temp;
vector<int> vc;
int main(){
	scanf("%d",&n);
	int m =n;
	while(m){
		scanf("%d",&temp);
		vc.push_back(temp);
		m--;
	}
	sort(vc.begin(),vc.end());
	int n1 = 0;
	int n2 = 0;
	if(n%2==0){
		for(int i=0;i<n/2;i++){
			n1 += vc[i];
		}
		for(int j= n/2;j<n;j++){
			n2 += vc[j];
		}
		printf("%d %d\n",0,abs(n1-n2));
		return 0;
	}
	else{
		for(int i=0;i<floor(n/2);i++){
			n1 += vc[i]	;
		}
		for(int i=floor(n/2);i<n;i++){
			n2 += vc[i];
		}
		printf("1 %d",abs(n1-n2));
	}
}
