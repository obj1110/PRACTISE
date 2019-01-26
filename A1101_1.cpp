#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 1000100;
const int INF = 0x7fffffff;

int array[maxn]={0};

int main(){
	int n,cts=0;
	scanf("%d",&n);
	
	int flag[n] = {0};
	
	for(int i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	//�������ȡ����������ߺ��ұ߷ֱ����
//	���Ҫ�ҵ��ǵ�ǰԪ����ߵ����ֵ
//	�ұ�Ҫ�ҵ��ǵ�ǰԪ�ص��ұߵ���Сֵ 
	int leftmax[n];
	int rightmin[n];
	memset(leftmax,0,n);
	memset(rightmin ,INF,n);
	//���ȴ���leftmax
	leftmax[0] = array[0];
	for(int i=1;i<n;i++){
	  if(leftmax[i-1] > array[i-1]) leftmax[i] = leftmax[i-1];
	  else leftmax[i] = array[i-1];
	}
	rightmin[n-1] = array[n-1];
	for(int i=n-2;i>=0;i--){
	  if(rightmin[i+1] < array[i+1]) rightmin[i] = rightmin[i+1];
	  else rightmin[i] = array[i+1];
	}
	//
	for(int i=0;i<n;i++){
	  if(array[i] >= leftmax[i] && array[i]<= rightmin[i]){
	    flag[cts] = array[i];
	    cts++;
	  }
	}
	cout<<cts<<endl;
	if(cts==0){
	  return 0;
	}
	
	for(int i=0;i<cts;i++){
	  printf("%d",flag[i]);
	  if(i!=cts-1) printf(" ");
	}
	printf("\n");
	return 0;
}
