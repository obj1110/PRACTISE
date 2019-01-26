#include<iostream>
#include<algorithm> 
#include<vector>

using namespace std;

const int maxn = 120;
//int array[maxn];
//int result[maxn];

vector<int> array; 
vector<int> result;
//��mergesort�ı��� 
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
		//sortĬ��������
		if(array == result){
			flag = 1;
			//���++iteԽ���˸���ô�죿��ֹԽ�� 
			if(ite+1==array.end()){
				break;
			}
			sort(array.begin(),++ite);
			break;
		}
	}
	//���
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
		//���Ĳ���Ӧ�����������ȵ�һ�� 
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
//			//�Ƚ϶��ߵĽ���Ĳ�� 
			if(array==result){
				printf("Merge Sort\n");
				gap *= 2;
				if(gap >=n) gap = n;
				//����Ϊ4��ʱ������������һ���ͻ����ite>ite2����� 
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
		//���ģ�� 
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
