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
	//t���ǵ�ǰ�о���Ԫ�ص����ǵڼ����� 
	int t = 0;
	int row = k;
	while(row){
		//���ȼ������һ�ŵ�Ԫ�صĸ������ 
		if(row ==k) {
			m = n - (n/k)*(k-1);
		}
		else{
			m = n/k;
		}
		// Ӧ����ֱ����һ�У�Ȼ��һ���ӡ�� 
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
