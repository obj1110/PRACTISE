#include<iostream>
#include<algorithm> 
#include<vector>

using namespace std;

const int maxn = 120;
//int array[maxn];
//int result[maxn];

vector<int> array; 
vector<int> result;
//给mergesort的保留 
vector<int> array_cpy;

 
bool cmp(int a[],int b[],int len){
	for(int i=0;i<len;i++) {
		if(a[i] != b[i]) return false;
	}
	return true;
}

int main(){
	int n,temp;
	scanf("%d",&n);
	
	
	int flag = -1;
	
	
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		array.push_back(temp);
	}
	
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		result.push_back(temp);
	}
	
	array_cpy = array;
	
	vector<int>::iterator ite;
	for(ite=array.begin();ite!=array.end();ite++){
		sort(array.begin(),ite);
		//sort默认是增序
		if(array == result){
			flag = 1;
			//如果++ite越界了该怎么办？防止越界 
			if(ite+1==array.end()){
				break;
			}
			sort(array.begin(),++ite);
			break;
		}
	}
	//输出
	if(flag == 1) {
		printf("Insertion Sort\n");
		int cts=0;
		vector<int>::iterator ite2;
		for(ite2 = array.begin();ite2!=array.end();ite2++) {
			printf("%d",*ite2);
			if(cts!=n-1){
				printf(" ");
			}
			cts++;
		}
	}
	//
	if(flag==-1){
		// 
		array = array_cpy;
		
		int gap;
		//最后的步长应该是整个长度的一半 
		vector<int>::iterator ite;
		vector<int>::iterator ite2;
		 
		for(gap=1;gap<=n;gap*=2){
			for(ite=array.begin();ite!=array.end();ite+=gap){
				ite2 = ite+2*gap;
				if(ite+gap > array.end()){
					ite2 = array.end();
				}
				sort(ite,ite2);
			}
//			//比较二者的结果的差别？ 
			if(array==result){
				printf("Merge Sort\n");
				gap *= 2;
				if(gap >=n) gap = n;
				//步长为4的时候，如果跟上面的一样就会出现ite>ite2的情况 
				for(ite = array.begin();ite!=array.end();ite+=gap) {
					ite2 = ite + 2*gap;
					if(ite+ gap > array.end()) {
						ite2 = array.end();
					}
					sort(ite,ite2);
				}
				break;
			}
		}
		//输出模块 
		int cts =0 ;
		for(ite = array.begin();ite!= array.end();ite++){
			printf("%d",*ite);
			if(cts!= n-1){
				printf(" ");
			}
			cts++;
		}
	} 
	return 0; 
}
