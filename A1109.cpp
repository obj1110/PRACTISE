#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
struct node{
	string name;
	int height;
};
 
int cmp(node a,node b){
	return a.height != b.height ? a.height > b.height :a.name <b.name; 
}

int main() {
	int n,m,k,i,j;
	cin>>n>>k;
	vector<node> stu(n) ;
	for(int i=0;i<n;i++){
		cin>>stu[i].name>>stu[i].height;
	}
	sort(stu.begin(),stu.end());
	//t就是当前研究的元素到底是第几个。 
	int t = 0;
	int row = k;
	while(row){
		//首先计算最后一排的元素的个数情况 
		if(row ==k) {
			m = n - (n/k)*(k-1);
		}
		else{
			m = n/k;
		}
		// 应该是直接排一行？然后一起打印？ 
		vector<string> stemp(m) ;
		stemp[m/2] = stu[t].name;
		//
		j = m/2 - 1; 
		for(i = t+1;i<t+m;i+=2){
			stemp[j--] = stu[i].name;
		}
		j = m/2+1;
		for(int )
	}
}
