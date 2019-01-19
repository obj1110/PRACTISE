#include<iostream> 
#include<algorithm>
#include<cstring>

using namespace std;

const int maxsize = 100010;

void swap(int &a,int &b){
	int t = a;
	a = b;
	b = t;
}

int array[maxsize];

int main(){
	int n;
	int cts=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	//ȷ��0��λ�� 
	int index = -1; 
	for(int i=0;i<n;i++){
		if(array[i]==0){
			index = i;
			break;
		}
	}
	
	bool flag = false; 
	//flag Ϊfalse��ʾ˵������м�ʹ��0��0��Ҳ����Ҫ���е����ġ� 
	while(!flag){
		flag = true;
		while(index != 0){
			//�����ķ�ʽѰ��ָ��Ԫ��ֵ��Ԫ�ص�λ�� 
			for(int i=0;i<n;i++){
				if(array[i]==index){
					swap(array[i],array[index]);
					cts++;
					index = i;
					//����ѭ��
					break;
				}
			}	
		}
		
		//�����е�Ԫ�ؽ��б�����ֻҪarray[i]��λ�ò���i������Ҫ���е����� 
		for(int i=0;i<n;i++){
			if(array[i]!=i){
				flag = false;
				swap(array[0],array[i]);
				//����0����λ�� 
				index = i; 
				cts++;
				break;
				//������Ҫ��������ѭ�� 
			}
		}
	}
	printf("%d\n",cts); 
	return 0;	
}
