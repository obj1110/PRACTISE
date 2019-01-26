#include<iostream>
#include<algorithm> 
#include<cstring>


using namespace std;

const int maxn = 120;
int array[maxn];
int result[maxn];
int array_cpy[maxn];

bool cmp(int a[],int b[],int len){
	for(int i=0;i<len;i++) {
		if(a[i] != b[i]) return false;
	}
	return true;
}

//没加引用是最大的错误 
void copy(int *source,int *destination,int len){
	for(int i=0;i<len;i++){
		destination[i] = source[i];
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int flag = -1;
	for(int i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
		for(int i=0;i<n;i++){
		scanf("%d",&result[i]);
	}
	
	memcpy(array_cpy,array,n);
	
	for(int i=1;i<n;i++){
		sort(array,array+i);
		if(cmp(array,result,n)){
			flag == 1;
			sort(array,array+i+1);
			break;
		}
	}
	
	
	
	//
	if(flag ==1 ){
		printf("Insertion Sort\n");
		int cts =0;
		for(int i=0;i<n;i++){
			printf("%d",array[i]);
			if(i!=n-1){
				printf(" ");	
			}
		}
		return 0;
	}
	//处理归并排序 
	int gap;
	if(flag == -1){
		memcpy(array,array_cpy,n);		
		for(gap =1;gap<=n;gap*=2){
//			cout<<"gap:"<<gap<<endl;
			for(int i=0;i<n;i+=gap){
				int j = i + gap;
				if( j > n ) j = n;		
				sort(array+i,array+j);
			}
			//比较数组
			int x;
			for(x=0;x<n;x++) {
				if(array[x] == result[x]) continue;
				else {
					break;
				}
			}
			if(x==n) {
				flag = 2;
				break;
			}
		}
	} 
	
	if(flag==2){
		printf("Merge Sort\n");
		gap*=2;
		if(gap>n ) gap =n;
		for(int i=0;i<n;i+=gap){
			int j = i + gap;
			if( j > n ) j = n;				
			sort(array+i,array+j);	
		}
			
		for(int i=0;i<n;i++) {
			printf("%d",array[i]);
			if(i!=n-1) printf(" ");
		}	
	}
	
	return 0;
}
