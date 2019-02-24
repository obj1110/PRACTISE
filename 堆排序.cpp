//���Լ�����һ����ȫ��������Ȼ���Ϊ�󶥶Ѻ�С���ѡ� 
#include<iostream> 
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 1010; 

//�����ϵĶ��е����ݣ���ʵ�������е����ݣ�
//һ������heap��һά�����д洢������ 


//��ʵ�Ƕ�ĳһ���ڵ���е��� 
void downAdjust(int low,int high) {
	//j�����ӣ� 
	int i = low,j = low*2;
	//���jû�г����Ͻ� 
	while(j <= high) {
		//�����Һ������Ҳ�ǲ����Ͻ�� 
		//����Ѱ��һ���Һ��ӣ�һ�����ߵ��Һ��� 
		if(j +1 <= high && heap[j+1] > heap[j]) {
			j = j + 1;
		}
		//�ӽڵ�͸�ĸ�ڵ���н��� 
		if( heap[j] > heap[i] ){
			swap(heap[i],heap[j]);
			i = j;
			j = i*2;
		}
		else{
			break;
		}
	}
}
//��ʵ���ǰ���һ����ԭ���heap��������heap��ʵ����һ������ 
void createHeap(){
	//Ҳ���ǵ��Ž���ö�ٲ��� 
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);
	} 
}
//ɾ��heap topԪ����ʵ���ǰ�heap topԪ�ؽ�����ȡ����ʵ���Ƕ������� 
void deleteTop() {
	//���Ƚ����滻 
	heap[1] = heap[n--];
	//Ȼ����жѵ��� 
	downAdjust(1,n); 
}

// �ڶ��У�����ڵ�Ĳ��� 
void upAdjust(int low,int high){
	int i = high;
	int j =i/2; 
	if(heap[j] < heap[i]){
		swap(heap[j],heap[i]);
		i = j;
		j = i/2;
	}
	else{
		//�����������յĺ��ʵ�λ�� 
		break;
	}
}
void insert(int x){
	heap[++n] = x;
	upAdjust(1,n);
}

void heapSort(){
	createHeap();
	for(int i = n ; i > 1 ; i++){
		//���Ƚ���һ��Ԫ�غ����һ��Ԫ�ؽ��н��� 
		swap(heap[i],heap[1]);
		//��Ҫ��Ϊ�˽�ʡ�ռ䣬ǰ���ǽ��õ�heap 
		//������ʣ�µ��������� 
		downAdjust(1,i-1);
	}
}

int main(){
	
	return 0;
}
