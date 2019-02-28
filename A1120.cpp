#include<set>
#include<iostream>
#include<algorithm>
using namespace std;
const int inf = 10010;

int cal(int number){
	int sum = 0 ;
	while(number >0){
		int temp = number%10;
		sum += temp;
		number -= temp;
		//这一步很重要的 
		number/=10;
	}
	return sum;
}

set<int> st;

int main() {
	int n,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		st.insert(cal(temp));
	}
	int size = st.size(); 
	printf("%d\n",size);
	for(auto &x:st) {
		printf("%d",x);
		if(size>1){
			printf(" ");
			size--;
		}
	}
	printf("\n");
	return 0;
}
