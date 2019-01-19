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
	//确定0的位置 
	int index = -1; 
	for(int i=0;i<n;i++){
		if(array[i]==0){
			index = i;
			break;
		}
	}
	
	bool flag = false; 
	//flag 为false表示说你的序列即使是0在0，也是需要进行调整的。 
	while(!flag){
		flag = true;
		while(index != 0){
			//遍历的方式寻找指定元素值的元素的位置 
			for(int i=0;i<n;i++){
				if(array[i]==index){
					swap(array[i],array[index]);
					cts++;
					index = i;
					//跳出循环
					break;
				}
			}	
		}
		
		//对所有的元素进行遍历，只要array[i]的位置不是i，就需要进行调整。 
		for(int i=0;i<n;i++){
			if(array[i]!=i){
				flag = false;
				swap(array[0],array[i]);
				//更新0的新位置 
				index = i; 
				cts++;
				break;
				//这样就要继续进行循环 
			}
		}
	}
	printf("%d\n",cts); 
	return 0;	
}
